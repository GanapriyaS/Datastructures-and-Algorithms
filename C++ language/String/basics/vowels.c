#include<stdio.h>

int main()
{
	char s[30];
	int i=0,vowels=0,cons=0;
	printf("Enter String : ");
	scanf("%s",s);
	printf("%s\n",s);
	
	for(i=0;s[i]!='\0';i++){
		if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
			vowels+=1;
		}
		else{
			cons+=1;
		}
	}	
	
	
	printf("Vowels : %d\nConstonents : %d",vowels,cons);
	return 0;
}
