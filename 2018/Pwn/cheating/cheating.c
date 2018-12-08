#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>

int authenticate(){
  
  char default_password[512]="822f0bbbd865d5e0caa02128ae974ef7379162066083130542bea0f4b427633b822f0bbbd865d5e0caa02128ae974ef7379162066083130542bea0f4b427633b822f0bbbd865d5e0caa02128ae974ef7379162066083130542bea0f4b427633b";
  char entered_password[512];
  fgets(entered_password,1025,stdin);
  if(strcmp(default_password,entered_password)==0){
    return 1;
  }
  else 
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
  printf("\nHey there\nWelcome to PASS (Password Authentication Security System)\nPAS is very simple\nIt is very powerful also\n");
  int value=authenticate();
  if(value){
    printf("\nI guess its not so powerful after all\n");
    system("/bin/sh");
  }
  else{
    printf("\nSee, I told you PAS was powerful\n");
    return 0;
  }
}
