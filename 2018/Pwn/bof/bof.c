#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int winner(){
	printf("\nAnd we have a winner folks\n");
	system("/bin/cat flag");
	return 0;
}
int exploit_me(){
	char buffer[10];
	printf("\nEnter a string\n(I really don't know why but you just have to)\n");
	gets(buffer);	
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
  printf("\nHello there\n");
  exploit_me();
  return 0;
}
