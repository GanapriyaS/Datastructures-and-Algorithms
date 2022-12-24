#include<stdio.h>

int main()
{
	char s[30];
	char temp;
	int i=0,len=0,j;
	printf("Enter String : ");
	gets(s);
	printf("%s\n",s);
	
	for(i=0;s[i]!='\0';i++){
		len=len+1;
	}
	printf("Length of the string : %d\n",len);
	
	j=len-1;
	for(i=0;i<j;i++,j--){
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
	}	
	
	printf("Reversed string : %s",s);
	return 0;
}
