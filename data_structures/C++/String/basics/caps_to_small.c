#include<stdio.h>

int main()
{
	char s[30];
	int i=0;
	printf("Enter String : ");
	scanf("%s",s);
	printf("%s\n",s);
	
	for(i=0;s[i]!='\0';i++){
		if(s[i]>=65 && s[i]<=90){
			s[i]+=32;
		}
		else if(s[i]>=97 && s[i]<=122){
			s[i]-=32;
		}
	}	
	
	
	printf("Alternated string : %s",s);
	return 0;
}
