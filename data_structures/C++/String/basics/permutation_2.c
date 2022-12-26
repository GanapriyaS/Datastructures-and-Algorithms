#include<stdio.h>

void permutation(char s[],int l,int h){
	int i;
	char temp;
	if(l==h){
		puts(s);
	}
	else{
		for(i=l;i<=h;i++){
				temp=s[l];
				s[l]=s[i];
				s[i]=temp;
				
				permutation(s,l+1,h);
				temp=s[l];
				s[l]=s[i];
				s[i]=temp;
			}
		}
	}

int main(){
	char s[30];
	int i=0,len=0,j,flag=1;
	printf("Enter String : ");
	gets(s);
	printf("%s\n",s);
	
	for(i=0;s[i]!='\0';i++){
		len=len+1;
	}
	printf("Length of the string : %d\n",len);
	
	permutation(s,0,len-1);
	
	return 0;
}
