#include<stdio.h>
int main()
{
	char a[30],b[30],hash[26]={0};
	int i=0;
	printf("Enter String[1] : ");
	gets(a);
	printf("Enter String[2] : ");
	gets(b);
	
	printf("%s | %s\n",a,b);
	
	for(i=0;a[i]!='\0';i++){
		hash[a[i]-97]+=1;
	}
	
	for(i=0;b[i]!='\0';i++){
		hash[b[i]-97]-=1;
	}
	
	for(i=0;i<26;i++){
		if(hash[i]!=0){
			printf("Not anagram");
			break;
		}				
	}
	if(i==26) printf("Anagram");
	
	return 0;
}
