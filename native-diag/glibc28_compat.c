/* Target-only adapters for the stock MIPS O32 glibc 2.8 symbol ABI.
 * Linux clock syscall avoids pulling librt/pthreads into this small collector.
 * Headers use 32-bit time/stat; never enable _TIME_BITS=64 or FILE_OFFSET_BITS=64.
 */
#define _GNU_SOURCE
#include <sys/stat.h>
#include <sys/syscall.h>
#include <time.h>
#include <unistd.h>
#if !defined(__mips__) || !defined(_MIPS_SIM) || _MIPS_SIM != 1
#error This compatibility source is only for MIPS O32.
#endif
typedef char assert_timespec_is_8[(sizeof(struct timespec)==8)?1:-1];
typedef char assert_stat_mode_offset_20[(__builtin_offsetof(struct stat, st_mode)==20)?1:-1];
extern int __fxstat(int, int, struct stat *);
extern int __lxstat(int, const char *, struct stat *);
extern int __fxstatat(int, int, const char *, struct stat *, int);
int fstat(int fd, struct stat *out) { return __fxstat(3, fd, out); }
int lstat(const char *path, struct stat *out) { return __lxstat(3, path, out); }
int fstatat(int fd, const char *path, struct stat *out, int flags) {
    return __fxstatat(3, fd, path, out, flags);
}
int clock_gettime(clockid_t clock, struct timespec *out) {
    return (int)syscall(SYS_clock_gettime, clock, out);
}
