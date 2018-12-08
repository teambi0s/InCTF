#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>

int winner(){
	system("/bin/sh");
}

int nope(){
	puts("Try again ?");
}

void (*fun_ptr)() = &nope;

int vuln(){
	char buf[16];
	int variable;
	printf("\nEnter a string\n");
	scanf("%15s",buf);
	printf("\nEnter a number\n");
	scanf("%d",variable);
}
int no_reason(){
	char buf[1024];
	printf("\nEnter a string again for no reason\n");
	fgets(buf,1025,stdin);
	return 0;
}

int initialize()
{
  alarm(30);
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);
  setvbuf(stdin, NULL, _IONBF, 0);
}


int main(){
  initialize();
  printf("\nLet me see you exploit this one\n");
  // evil patch XD !
  __asm__("movl $0x804a030,0x24(%esp)");
  no_reason();
  vuln();
  (*fun_ptr)();
  return 0;
}
