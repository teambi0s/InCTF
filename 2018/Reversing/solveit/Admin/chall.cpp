#include<string.h>
#include<cstring>
#include<fstream>
#include<stdio.h>
#include<string>
#include<iostream>
#include<limits.h>
#include<experimental/filesystem>
#include<unistd.h>
#include<bits/stdc++.h> 
using namespace std;
int main(){
	int flag;
	/*string path= std::experimental::filesystem::current_path();
    	char delim[] = "/";
	char str[path.length()+1];	
	int i=0;
	for(i=0;i<path.length();i++)
		str[i]=path[i];
	str[i]='\0';
    	char *token = strtok(str,delim);
    	string s[100];
	int j=0;
	while (token)
    	{
        	s[j]=token;
        	token = strtok(NULL,delim);
		j++;
    	}
	string secret=s[j-1];*/
	string secret;
	cout<<"Find the right string to get your flag............"<<endl;
	cin>>secret;
	int sum=0,an=0,n=0;
	long int pro=1;
	for(int i=0;i<secret.length();i++){
		if((secret[i]>=48&&secret[i]<=57)||(secret[i]>=65&&secret[i]<=122))
			n++;
	}
	if(n==secret.length()){
	if(secret.length()==8){
		for(int i=0;i<secret.length();i++)
			sum+=secret[i];
		for(int i=0;i<secret.length();i++)
                        pro*=secret[i];
		for(int i=0;i<secret.length();i++)
                        an^=secret[i];
		if(sum==647&&pro==1018068377040000&&an==59){
			int next=secret[1]+secret[2]+secret[4]+secret[5]-4*48;		
			if(next==14){
				if(secret[0]*secret[0]==12100&&secret[4]*secret[4]==2601){
					int l=0,m=0,n=0;
					for(int i=0;i<secret.length()/2;i++)
                        			l^=secret[i];
					for(int i=secret.length()/2;i<secret.length();i++)
                        			m^=secret[i];
					for(int i=1;i<secret.length();i+=2)
                        			n^=secret[i];
					if(l==54&&m==13&&n==34)
						flag=1;
					}
					else
						flag=0;	
				}
			else
				flag=0;
			}
		else
			flag=0;
	}
	else 
		flag=0;
	}
	else
		flag=0;
	if(flag==1){
		cout<<"yeah, got it right!!"<<endl;
		cout<<"here's your flag---"<<endl;
		ifstream myfile ("flag.txt");
		string line;
  		if (myfile.is_open())
  		{
    			while (getline (myfile,line))
    			{
      				cout << line << '\n';
    			}
    			myfile.close();
  		}
		else cout << "Unable to open file"; 

	}
	else 
		cout<<"nope try again";
	
	return 0;
}
