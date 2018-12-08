#include "libc.h"

void main() {
        char s[15] = "000000000000000"; 
        puts("Simple Right?!\n\n");
        puts("Enter the Password: \n\n");
        read(0,s,15);
        if(!strcmp(s,"eW93dGZob3d0aGl"))
        {
                puts("Flag : inctf{");
                puts(s);
                puts("}\n");
        }else
                puts("Maybe Try Again!\n");
        exit(0);
}
