#include<stdio.h>

int main()
{
	char s[30];
	int len,i=0;
	printf("Enter String : ");
	scanf("%s",s);
	printf("%s\n",s);
	
	for(i=0;s[i]!='\0';i++){
		len=len+1;
	}	
	
	printf("Length of the string : %d",len);
	return 0;
}
