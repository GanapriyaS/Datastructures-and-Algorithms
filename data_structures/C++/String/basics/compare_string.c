#include<stdio.h>
//smaller letters have greater value than capital letters
int main()
{
	char a[30],b[30];
	int i=0;
	printf("Enter String[1] : ");
	gets(a);
	printf("Enter String[2] : ");
	gets(b);
	
	printf("%s | %s\n",a,b);
	
	for(i=0;a[i]!='\0',b[i]!='\0';i++){
		if(a[i]!=b[i]){
			break;
		}
	}
	
	if(a[i]==b[i]) printf("Equal");
	else if(a[i]>=b[i]) printf("a is greater");
	else printf("b is greater");
	
	return 0;
}
