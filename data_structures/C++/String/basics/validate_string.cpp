#include<stdio.h>
int validate(char *s)
{
	int i=0;
	for(i=0;s[i]!='\0';i++){
		if(!(s[i]>=65 && s[i]<=90) && !( s[i]>=97 && s[i]<=122 ) && !(s[i]>=48 && s[i]<=57)){
			return 0;
		}
	}
	return 1;
}
int main()
{
	char s[30];
	int flag=0;
	printf("Enter String : ");
	scanf("%s",s);
	printf("%s\n",s);
	flag= validate(s);
	if(flag)
	{
		printf("Valid");
	}
	else{
		printf("Not valid");
	}
	return 0;
}
