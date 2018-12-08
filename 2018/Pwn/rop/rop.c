#include <stdio.h>
#include <unistd.h>

int initialize()
{
  alarm(30);
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);
  setvbuf(stdin, NULL, _IONBF, 0);
}

void main()
{
  char buf[0x10]={0};
  initialize();
  puts("Welcome fellow hackers \nCan you rop your way to shell ?\n");
  read(0,buf,0x100);
}
