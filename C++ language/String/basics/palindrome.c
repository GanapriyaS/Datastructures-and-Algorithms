#include<stdio.h>

int main()
{
	char s[30];
	int i=0,len=0,j,flag=1;
	printf("Enter String : ");
	gets(s);
	printf("%s\n",s);
	
	for(i=0;s[i]!='\0';i++){
		len=len+1;
	}
	printf("Length of the string : %d\n",len);
	
	j=len-1;
	for(i=0;i<j;i++,j--){
		if(!(s[i]==s[j])){
			flag=0;
			break;
		}
	}	
	
	if(flag){
		printf("Palindrome");
	}
	else{
		printf("Not a Palindrome");
	}
	
	return 0;
}
