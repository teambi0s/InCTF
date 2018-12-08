#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include<stdlib.h>
char inctf[]={'i','n','c','t','f','{'};
char str[]={'i','o','5',']','^',',','l','n','o','r','Z','l','g','j','s','\\','\\','q','a','h','j','\\','w','p','r','f','l','u','n','^','c','f','u','p','^'};
char check[]={'o',']','^','i','5','l','o','r',',','n','l','j','s','Z','g','\\','a','h','\\','q','\\','p','r','j','w','l','n','^','f','u','f','p','^','c','u'
};
	char array1[] = {'9', '3', '2', '6', 'a', '9', '2', '6', 'b', '5', '0', '0', '3', '9', '5', '2', '4', '4', '4', '2', '5', '6', '0', '6', '7', '3', '3', '7', '9', '4', '8', '3', '7', '7', '6', '9', '6', '6', '1', '0', '2', '1', '0', '1', '0', '3', '9', '2', '5', '3', '9', '0', '0', '6', '6', '8', '7', '1', '1', '4', '3', '1', '2', '6', '2', '6', '1', '2', '8', '3', '8', '5', '2', '0', '7', '7', '1', '1', '2', '6', '7', '5', '0', '5', '4', '3', '8', '0', '4', '4', '4', '8', '7', '1', '0', '9', '4', '9', '8', '0'};
bool isMultipleof5 (int n) 
{ 
    while ( n > 0 ) 
        n = n - 5; 
  
    if ( n == 0 ) 
        return true; 
  
    return false; 
} 
void xoring(char * input,int k){
	if (k==7){
		for (int i=0;i<strlen(input);i++){
			input[i]=input[i]^(array1[i]^((i*k)%10));
		}
	}
	return;
}

void transposition(char *input,int len, char *string, char *temp,char *transpos){
	int i=0,j=0,k=0,z=0;
	char ch;
	do {	
       	for( ; (ch = input[i]) !='\0' && ch != '\n';++i){
       	    temp[j++] = ch;
       	    if(j == len){
       	        j=0;
       	        ++i;
        	        break;
        	    }
        	}
        	for(k=0;i && k<len;++k){
        	     string[z]=temp[transpos[k]];
				 z++;
        	}
			if(z==35){
				string[z]='\0';
			} 
    	}while(ch != '\n' && ch != '\0' && i!=strlen(input));
	return;
	}

bool check_transposition(char *input,int len,char *temp){
	char string[35];
	char transpose[]={4,2,1,3,0};
	transposition(&input[0],len,&string[0],&temp[0],&transpose[0]);
	if (strcmp(string,str)==0)
		return true;
	return false;	
}

int main(int argc,char *argv[])
{
    char transpos[]={2,4,0,1,3};
	int z=0,len = sizeof(transpos),i, j, k;
	
    char input[100], string[35], ch, temp[len];
	scanf("%s",input);
	bool s=isMultipleof5(strlen(input));
	if (argc>1)
		{
		i=atoi(argv[1]);
		j=atoi(argv[2]);
		k=(i*j)%10;
		if (s)
			{
			xoring(&input[0],k);
			transposition(&input[0], len, &string[0], &temp[0], &transpos[0]);
			s=check_transposition(&string[0],len,&temp[0]);
			if (s)
			{
    			for (int z=0;z<strlen(input);z++)
				{
						string[z]=string[z]+(z%5+1);
				}
				printf("%s%s}",inctf,string);
			}
			else 
			printf("Missed it!");
		}
		else 
			printf("Missed it!");
		}
	else 
		printf("Missed it!");	
    return 0;
}
