#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h>


char *year=NULL;
int month=0;
char *admin = NULL;

int add_admin(){
	char buffer[10];
	printf("Enter admin name\n");
	fgets(buffer,10,stdin);
	admin = strdup(buffer);
	return 0;
}

int filter(char *buffer){
	char *src,*dst;
	for(src = buffer,dst = buffer;*src;src++)
		if(*src>=0x30 && *src<=0x39)
			*dst++ = *src;
	*dst=0;
	return 0;
}

int print_menu(){
	char buffer[10];
	puts("\n\nSuper awesome Calendar");
	printf("1: Add year\n2: Add month\n3: Show calendar\n4: Add admin\n5: Remove year\n6: Exit\n>> ");
	fgets(buffer,10,stdin);
	int choice = atoi(buffer);
	return choice;
}

int show_calendar(){
	if(month==0){
		printf("Month not set\n");
		return 0;
	}
	if(year==NULL){
		printf("Year not set\n");
		return 0;
	}
	char *cmd = strdup("cal %d %s");
	char buffer[20];
	sprintf(buffer,cmd,month,year);
	system(buffer);
	return 0;
}

int add_year(){
	char buffer[10];
	printf("Enter the year\n");
	fgets(buffer,10,stdin);	
	filter(buffer);
	year = strdup(buffer);
	return 0;
}

int remove_year(){
	if(year == NULL){
		printf("Year is empty\nCannot free\n");
		return 0;
	}
	free(year);
	return 0;
}

int add_month(){
	char buffer[10];
	printf("Enter the month (1-12)\n");
	fgets(buffer,10,stdin);
	month = atoi(buffer);
	if(month<0||month>12){
		printf("Wrong input\n");
		return 1;
	}
	return 0;
}
void initialize()
{
  alarm(30);
  setvbuf(stdout, NULL, _IONBF, 0);
  setvbuf(stderr, NULL, _IONBF, 0);
  setvbuf(stdin, NULL, _IONBF, 0);
}

int main(){
  initialize();
  while(1){
    switch(print_menu()){
    case 1: add_year();break;
    case 2: add_month();break;
    case 3: show_calendar();break;
    case 4: add_admin();break;
    case 5: remove_year();break;
    case 6: puts("Bye");exit(0);
    default: puts("Invalid choice");break;
    }
  }
  return 0;
}	
