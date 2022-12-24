#include<stdio.h>

int main()
{
	char s[30];
	int i=0;
	long int x=1,h=0;
	printf("Enter String : ");
	scanf("%s",s);
	printf("%s\n",s);
	
	for(i=0;s[i]!='\0';i++){
		x=1;
		x=x<<(s[i]-97);
		if(x&h>0) printf("%c : duplicate\n",s[i]);
		else h=x|h;
	}	
	return 0;
}
