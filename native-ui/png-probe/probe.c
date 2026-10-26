/* Fixed-input libpng12 probe. No TV services, external commands or devices. */
typedef unsigned int u32;
typedef unsigned long usize;
typedef unsigned char u8;
typedef void *ptr;
extern int open(const char *, int, ...);
extern int close(int);
extern int read(int, void *, unsigned int);
extern int write(int, const void *, unsigned int);
extern void *malloc(usize);
extern void free(void *);
extern void _exit(int);
extern ptr png_create_read_struct(const char *, ptr, ptr, ptr);
extern ptr png_create_info_struct(ptr);
extern void png_destroy_read_struct(ptr *, ptr *, ptr *);
extern void png_set_read_fn(ptr, ptr, void (*)(ptr,u8 *,usize));
extern ptr png_get_io_ptr(ptr);
extern void png_read_info(ptr,ptr);
extern u32 png_get_IHDR(ptr,ptr,u32 *,u32 *,int *,int *,int *,int *,int *);
extern u32 png_get_valid(ptr,ptr,u32);
extern void png_set_palette_to_rgb(ptr);
extern void png_set_tRNS_to_alpha(ptr);
extern void png_set_add_alpha(ptr,u32,int);
extern void png_read_update_info(ptr,ptr);
extern usize png_get_rowbytes(ptr,ptr);
extern void png_read_image(ptr,u8 **);
extern void png_read_end(ptr,ptr);
static void text(const char *s) {const char *p=s;while(*p)p++;write(1,s,p-s);}
static void number(u32 n) {char s[12];int p=12;do{s[--p]='0'+n%10;n/=10;}while(n);write(1,s+p,12-p);}
static void field(u32 n) {text(" ");number(n);}
static void error(ptr p, const char *s) {(void)p;(void)s;_exit(90);}
static void warning(ptr p, const char *s) {(void)p;(void)s;}
static void input(ptr p,u8 *out,usize n) {
 int fd=(int)png_get_io_ptr(p);
 while(n) {int got=read(fd,out,n);if(got<=0)_exit(91);n-=got;out+=got;}
}
static int decode(const char *name) {
 int fd=open(name,0);u32 w=0,h=0;int bits=0,type=0,i=0,c=0,f=0;
 ptr p,info;u8 *pixels,**rows;usize stride;u32 y;
 if(fd<0)return 20;
 p=png_create_read_struct("1.2.32",0,(ptr)error,(ptr)warning);
 if(!p)return 21;
 info=png_create_info_struct(p);if(!info)return 22;
 png_set_read_fn(p,(ptr)fd,input);png_read_info(p,info);
 png_get_IHDR(p,info,&w,&h,&bits,&type,&i,&c,&f);
 if(w!=69||h!=620||bits!=4||type!=3)return 23;
 u32 trns=png_get_valid(p,info,0x10)!=0;
 png_set_palette_to_rgb(p);
 if(trns)png_set_tRNS_to_alpha(p);else png_set_add_alpha(p,255,1);
 png_read_update_info(p,info);stride=png_get_rowbytes(p,info);
 if(stride!=w*4)return 24;
 pixels=malloc(stride*h);rows=malloc(h*sizeof(*rows));if(!pixels||!rows)return 25;
 for(y=0;y<h;y++)rows[y]=pixels+y*stride;
 png_read_image(p,rows);png_read_end(p,info);
 text("PNG");field(w);field(h);field(bits);field(type);field(trns);
 u32 points[]={0,w-1,(h-1)*w,h*w-1,(h/2)*w+w/2};
 for(y=0;y<5;y++) {u32 k;for(k=0;k<4;k++)field(pixels[4*points[y]+k]);}
 text("\n");
 png_destroy_read_struct(&p,&info,0);free(rows);free(pixels);close(fd);return 0;
}
int probe_main(void) {
 int a=decode("/inputs/original.png");if(a)return a;
 a=decode("/inputs/v2.png");if(a)return a;
 return decode("/inputs/rounded.png");
}
