/* Opt-in RAM FIFO collector. No TV/hardware code is executed by host tests.
 * Native producers must open FIFO O_RDWR|O_NONBLOCK|O_NOFOLLOW per record,
 * verify path/FD FIFO type, write <=192 bytes once, then close. Never stdout.
 * Historical v2 did not check producer-side owner/mode. Final v3 additionally
 * checks root owner and exact 0600 at path and opened-FD validation stages.
 * USB discovery and writes happen only in a bounded, killable child worker.
 */
#define _GNU_SOURCE
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include <poll.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define RING_COUNT 64
#define LINE_BYTES 192
#define SNAPSHOT_LIMIT 16384
#define MARKER "MODGRUNDIG_DIAG_ENABLE"
#define OUTPUT "MODGRUNDIG_DIAG.txt"
#define TEMP ".MODGRUNDIG_DIAG.tmp"

struct record { char text[LINE_BYTES]; size_t len; };
struct state {
    struct record ring[RING_COUNT];
    unsigned pos, count;
    uint32_t accepted, rejected, overlong;
};
static volatile sig_atomic_t stopping;
static void stop_handler(int sig) { (void)sig; stopping = 1; }
static uint64_t now_ms(void) {
    struct timespec t;
    if (clock_gettime(CLOCK_MONOTONIC, &t)) return 0;
    return (uint64_t)t.tv_sec*1000u+(unsigned)t.tv_nsec/1000000u;
}

/* Canonical numeric schema only; arbitrary log messages/IDs never persist. */
static int valid_record(const char *s, size_t len) {
    uint32_t fields[10];
    size_t at=7, n=0;
    if (len < 11 || len >= LINE_BYTES || memcmp(s,"MGDIAG ",7)) return 0;
    while (at < len) {
        uint32_t v=0;
        unsigned digits=0;
        if (n == 10) return 0;
        while (at<len && s[at]>='0' && s[at]<='9') {
            unsigned d=(unsigned)(s[at++]-'0');
            if (++digits>10 || v>(UINT32_MAX-d)/10u) return 0;
            v=v*10u+d;
        }
        if (!digits) return 0;
        fields[n++]=v;
        if (at==len) break;
        if (s[at++]!=' ' || at==len) return 0;
    }
    if (fields[0]==1 && n==9)
        return fields[2]<=255 && fields[3]<=255 && fields[4]<=8191 &&
               fields[5]<=8191 && fields[6]<=8191 && fields[7]<=255;
    if (fields[0]==2 && n==3) return fields[1]<=255;
    if (fields[0]==3 && n==4) return fields[2]<=31;
    return 0;
}
static void accept_line(struct state *s, const char *line, size_t len) {
    if (!valid_record(line,len)) { s->rejected++; return; }
    memcpy(s->ring[s->pos].text,line,len);
    s->ring[s->pos].text[len]='\n';
    s->ring[s->pos].len=len+1;
    s->pos=(s->pos+1)%RING_COUNT;
    if (s->count<RING_COUNT) s->count++;
    s->accepted++;
}
static int write_all(int fd, const void *data, size_t len) {
    const char *p=data;
    while (len) {
        ssize_t n=write(fd,p,len);
        if (n<0 && errno==EINTR) continue;
        if (n<=0) return 0;
        p+=n; len-=(size_t)n;
    }
    return 1;
}
static int usb_device(const char *s) {
    size_t i=7;
    if (strncmp(s,"/dev/sd",7) || s[i]<'a' || s[i]>'z') return 0;
    i++;
    while (s[i]>='a' && s[i]<='z') i++;
    if (!s[i]) return 1;
    if (s[i]<'1' || s[i]>'9') return 0;
    do { i++; } while (s[i]>='0' && s[i]<='9');
    return s[i]=='\0';
}
static int mount_decode(char *s) {
    size_t in=0,out=0;
    while (s[in]) {
        unsigned c=(unsigned char)s[in++];
        if (c=='\\') {
            if (!s[in] || !s[in+1] || !s[in+2]) return 0;
            if (s[in]<'0'||s[in]>'7'||s[in+1]<'0'||s[in+1]>'7'||s[in+2]<'0'||s[in+2]>'7') return 0;
            c=(unsigned)(s[in]-'0')*64u+(unsigned)(s[in+1]-'0')*8u+(unsigned)(s[in+2]-'0');
            in+=3;
            if (!c || c>255) return 0;
        }
        s[out++]=(char)c;
    }
    s[out]='\0';
    return s[0]=='/';
}
static int mount_fields(const char *line, char *dev, char *point, char *fs, char *opts) {
    char *outputs[4]={dev,point,fs,opts};
    size_t sizes[4]={256,2048,64,512};
    unsigned i;
    for (i=0;i<4;i++) {
        size_t n=0;
        while (*line==' ' || *line=='\t') line++;
        while (*line && *line!=' ' && *line!='\t' && *line!='\n') {
            if (n+1>=sizes[i]) return 0;
            outputs[i][n++]=*line++;
        }
        if (!n) return 0;
        outputs[i][n]='\0';
    }
    return 1;
}
static int marker_present(int dirfd) {
    char text[10];
    struct stat st;
    int fd=openat(dirfd,MARKER,O_RDONLY|O_NONBLOCK|O_NOFOLLOW|O_CLOEXEC);
    ssize_t n;
    if (fd<0) return 0;
    if (fstat(fd,&st) || !S_ISREG(st.st_mode) || st.st_size!=8) { close(fd); return 0; }
    n=read(fd,text,sizeof(text)); close(fd);
    return n==8 && !memcmp(text,"MGDIAG1\n",8);
}
static int export_snapshot(int dirfd, const struct state *s) {
    char buf[SNAPSHOT_LIMIT];
    struct stat st;
    size_t length;
    unsigned i;
    int fd, ok;
    int n=snprintf(buf,sizeof(buf),"MGDIAG_META 1 %u %u %u %u\n",
                   s->accepted,s->rejected,s->overlong,s->count);
    if (n<0 || (size_t)n>=sizeof(buf)) return 0;
    length=(size_t)n;
    for (i=0;i<s->count;i++) {
        const struct record *r=&s->ring[(s->pos+RING_COUNT-s->count+i)%RING_COUNT];
        if (length+r->len>sizeof(buf)) return 0;
        memcpy(buf+length,r->text,r->len); length+=r->len;
    }
    /* Never follow output/temp symlinks or overwrite unrelated temporary data. */
    if (!fstatat(dirfd,TEMP,&st,AT_SYMLINK_NOFOLLOW)) {
        /* A killed writer may leave this bounded, owned scratch file. */
        /* FAT/NTFS expose mount-wide modes rather than the requested 0600.
         * Opt-in reserves this exact scratch name; never follow its symlinks. */
        if (!S_ISREG(st.st_mode) || st.st_uid!=geteuid() || st.st_nlink!=1 ||
            st.st_size>SNAPSHOT_LIMIT || unlinkat(dirfd,TEMP,0)) return 0;
    } else if (errno!=ENOENT) return 0;
    fd=openat(dirfd,TEMP,O_WRONLY|O_CREAT|O_EXCL|O_NOFOLLOW|O_CLOEXEC,0600);
    if (fd<0) return 0;
    ok=write_all(fd,buf,length);
    if (ok && fsync(fd)) ok=0;
    if (close(fd)) ok=0;
    if (ok && !marker_present(dirfd)) ok=0;
    if (ok && renameat(dirfd,TEMP,dirfd,OUTPUT)) ok=0;
    /* Some removable filesystems do not support directory fsync. An EINVAL
     * result means rename durability is not proven, not that the export failed.
     * All sync I/O remains in the worker protected by the parent deadline. */
    if (ok && fsync(dirfd) && errno!=EINVAL) ok=0;
    if (!ok) unlinkat(dirfd,TEMP,0);
    return ok;
}
/* All potentially blocking removable-filesystem operations stay in this child.
 * A held directory FD ensures unmount cannot redirect writes onto internal flash.
 */
static int worker_snapshot(const char *mounts, const struct state *s) {
    FILE *f=fopen(mounts,"r");
    char line[4096],dev[256],mountpoint[2048],fs[64],opts[512];
    int enabled=0;
    if (!f) return 0;
    while (fgets(line,sizeof(line),f)) {
        int fd;
        if (!strchr(line,'\n')) continue;
        if (!mount_fields(line,dev,mountpoint,fs,opts)) continue;
        if (!usb_device(dev) || !mount_decode(mountpoint)) continue;
        if (strcmp(fs,"vfat") && strcmp(fs,"exfat") && strcmp(fs,"ntfs") &&
            strcmp(fs,"fuseblk") && strcmp(fs,"ext2") && strcmp(fs,"ext3") && strcmp(fs,"ext4")) continue;
        if (strncmp(opts,"rw,",3) && strcmp(opts,"rw")) continue;
        fd=open(mountpoint,O_RDONLY|O_DIRECTORY|O_NOFOLLOW|O_CLOEXEC);
        if (fd<0) continue;
        if (marker_present(fd)) {
            enabled=1;
            (void)export_snapshot(fd,s);
            close(fd);
            break; /* At most one opted-in volume; bounded data per interval. */
        }
        close(fd);
    }
    fclose(f);
    return enabled;
}
static void remove_fifo(const char *path, const struct stat *owned);
static int create_fifo(const char *path, struct stat *owned) {
    struct stat actual;
    char pending[4096];
    size_t len=strlen(path);
    int fd=-1;
    if (len>sizeof(pending)-9) return -1;
    memcpy(pending,path,len); memcpy(pending+len,".pending",9);
    if (!lstat(path,&actual)) return -1; /* Refuse existing object, including live sink. */
    if (errno!=ENOENT || mkfifo(pending,0600)) return -1;
    if (lstat(pending,owned)) return -1;
    if (!S_ISFIFO(owned->st_mode) || owned->st_uid!=geteuid()) goto fail;
    fd=open(pending,O_RDWR|O_NONBLOCK|O_NOFOLLOW|O_CLOEXEC);
    if (fd<0) goto fail;
    if (fstat(fd,&actual) || actual.st_ino!=owned->st_ino || actual.st_dev!=owned->st_dev ||
        !S_ISFIFO(actual.st_mode) || actual.st_uid!=geteuid() || (actual.st_mode&0777)!=0600) goto fail;
    /* Publish only after the reader exists. A fast RDWR producer must never
     * write+close the last FD before the collector has opened its read end.
     * link() is atomic and refuses an existing destination on Linux 3.1;
     * rename() would introduce an overwrite race without newer renameat2(). */
    if (link(pending,path)) goto fail;
    if (unlink(pending)) { remove_fifo(path,owned); goto fail; }
    return fd;
fail:
    if (fd>=0) close(fd);
    remove_fifo(pending,owned);
    return -1;
}
static void remove_fifo(const char *path, const struct stat *owned) {
    struct stat actual;
    if (!lstat(path,&actual) && S_ISFIFO(actual.st_mode) &&
        actual.st_ino==owned->st_ino && actual.st_dev==owned->st_dev) unlink(path);
}
int main(int argc, char **argv) {
    const char *fifo="/tmp/modgrundig-diag.fifo",*mounts="/proc/mounts";
    unsigned duration=0,interval=2000,timeout=1500;
    uint64_t start,next_worker=0,worker_started=0;
    pid_t worker=-1;
    int fifo_fd=-1,status_fd=-1,enabled=0,worker_killed=0;
    struct state state;
    struct stat owned;
    char partial[LINE_BYTES];
    size_t partial_len=0;
    int discard=0,i,exit_code=0;
    memset(&state,0,sizeof(state)); memset(&owned,0,sizeof(owned));
    umask(077);
    for (i=1;i<argc;i++) {
        if (!strcmp(argv[i],"--fifo") && i+1<argc) fifo=argv[++i];
        else if (!strcmp(argv[i],"--mounts") && i+1<argc) mounts=argv[++i];
        else if (!strcmp(argv[i],"--duration") && i+1<argc) duration=(unsigned)strtoul(argv[++i],0,10);
        else if (!strcmp(argv[i],"--interval-ms") && i+1<argc) interval=(unsigned)strtoul(argv[++i],0,10);
        else if (!strcmp(argv[i],"--worker-timeout-ms") && i+1<argc) timeout=(unsigned)strtoul(argv[++i],0,10);
        else return 64;
    }
    if (!interval || !timeout || duration>86400) return 64;
    signal(SIGTERM,stop_handler); signal(SIGINT,stop_handler);
    start=now_ms();
    while (!stopping && (!duration || now_ms()-start<(uint64_t)duration*1000u)) {
        struct pollfd pfds[2];
        uint64_t now=now_ms();
        if (worker<0 && status_fd<0 && now>=next_worker) {
            int p[2];
            if (!pipe(p)) {
                int flags=fcntl(p[0],F_GETFL);
                (void)fcntl(p[0],F_SETFL,flags|O_NONBLOCK);
                worker=fork();
                if (worker==0) {
                    char result;
                    signal(SIGTERM,SIG_DFL); signal(SIGINT,SIG_DFL);
                    close(p[0]);
                    if (fifo_fd>=0) close(fifo_fd);
                    result=worker_snapshot(mounts,&state)?'1':'0';
                    if (write(p[1],&result,1)!=1) _exit(1);
                    close(p[1]); _exit(0);
                }
                close(p[1]);
                if (worker<0) close(p[0]);
                else { status_fd=p[0]; worker_started=now; worker_killed=0; }
            }
            next_worker=now+interval;
        }
        if (worker>0 && now-worker_started>timeout && !worker_killed) {
            (void)kill(worker,SIGKILL); worker_killed=1;
            /* Never create another child until this one has been reaped. */
        }
        pfds[0].fd=fifo_fd; pfds[0].events=POLLIN; pfds[0].revents=0;
        pfds[1].fd=status_fd; pfds[1].events=POLLIN; pfds[1].revents=0;
        (void)poll(pfds,2,50);
        if (status_fd>=0 && (pfds[1].revents&POLLIN)) {
            char result;
            if (read(status_fd,&result,1)==1) {
                int wanted=result=='1';
                if (wanted && !enabled) {
                    fifo_fd=create_fifo(fifo,&owned);
                    if (fifo_fd<0) { exit_code=78; stopping=1; continue; }
                } else if (!wanted && enabled) {
                    close(fifo_fd); fifo_fd=-1; remove_fifo(fifo,&owned);
                    memset(&state,0,sizeof(state)); partial_len=0; discard=0;
                }
                enabled=wanted;
                close(status_fd); status_fd=-1;
            }
        }
        if (status_fd>=0 && (pfds[1].revents&POLLHUP) && !(pfds[1].revents&POLLIN)) {
            close(status_fd); status_fd=-1;
        }
        if (fifo_fd>=0 && (pfds[0].revents&POLLIN)) {
            char input[1024];
            ssize_t n=read(fifo_fd,input,sizeof(input)),j;
            for (j=0;j<n;j++) {
                if (input[j]=='\n') {
                    if (!discard) accept_line(&state,partial,partial_len);
                    else state.overlong++;
                    partial_len=0; discard=0;
                } else if (!discard) {
                    if (partial_len>=LINE_BYTES-1) discard=1;
                    else partial[partial_len++]=input[j];
                }
            }
        }
        if (worker>0) {
            int status;
            pid_t done=waitpid(worker,&status,WNOHANG);
            /* A reaped child may have written just after poll timed out. Keep
             * its pipe until the next poll drains the result instead of losing
             * that last marker state in the waitpid/read race. */
            if (done==worker) worker=-1;
        }
    }
    if (fifo_fd>=0) { close(fifo_fd); remove_fifo(fifo,&owned); }
    if (status_fd>=0) close(status_fd);
    if (worker>0) { (void)kill(worker,SIGKILL); (void)waitpid(worker,0,WNOHANG); }
    return exit_code;
}
