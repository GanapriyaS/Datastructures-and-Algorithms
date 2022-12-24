#include<stdio.h>

int main()
{
	char s[30];
	char hash[26]={0};
	int i=0;
	printf("Enter String : ");
	gets(s);
	printf("%s\n",s);
	
	for(i=0;s[i]!='\0';i++){
		hash[s[i]-97]+=1;
	}
	
	for(i=0;i<26;i++){
		if(hash[i]!=0)
			printf("%c : %d\n",i+97,hash[i]);
	}
	
	return 0;
}
