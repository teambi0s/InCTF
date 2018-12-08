#include "libc.h"

#define no_decomp_pls \
    __asm__ ("  push     %rax      \n"\
             "  xor      %eax, %eax \n"\
             "  jz       haha   \n"\
             "  add      $0x4 ,%rsp  \n"\
             "haha:             \n"\
             "  pop      %rax      \n");



int strcmp(const char *s1, const char *s2){
	no_decomp_pls;
        unsigned char s3[15] = "000000000000000";
        char s4[15] = {176, 164, 104, 194, 206, 132, 162, 210, 154, 132, 222, 106, 152, 82, 110};
        for(int i = 0; i < 15; i++)
        {
                s3[i] = *(s1 + i);
                s3[i] = ((s3[i] >> 5) | (s3[i] << 3) & 0xff);            
        }
        for(int i = 0; i < 15; i++)
        {
                s3[i] = ((s3[i] >> 2) | (s3[i] << 6) & 0xff);            
        }
        int ret = strncmp(s3,s4,15);
        return ret;
}

size_t strlen(const char* s)
{
    size_t l;
    for (l = 0; *s; s++, l++);
    return l;
}

int puts(const char* s)
{
    write(1, s, strlen(s));
    return 1;
}

ssize_t read(int fd, void *buf, size_t count)
{
	reader(fd, buf, count);
}

