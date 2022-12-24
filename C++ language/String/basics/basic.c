#include<stdio.h>

int main()
{
	char a[]="Priya";
	char *p = "Priya";
	char name[]={'P','r','i','y','a'};
	
	printf("%s\n",name);
	printf("%s\n",p);
	
	printf("Enter String : ");
	gets(name);
	puts(name);
	
	printf("Enter another string : ");
	scanf("%s",name);
	printf("%s\n",name);	
	return 0;
}
