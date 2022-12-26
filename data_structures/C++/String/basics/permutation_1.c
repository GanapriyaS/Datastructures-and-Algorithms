#include<stdio.h>

void permutation(char s[],int k){
	static int A[10]={0};
	static char res[10];
	int i;
	
	if(s[k]=='\0'){
		res[k]='\0';
		puts(res);
	}
	else{
		for(i=0;s[i]!='\0';i++){
			if(A[i]==0){
				res[k]=s[i];
				A[i]=1;
				permutation(s,k+1);
				A[i]=0;
			}
		}
	}
}

int main(){
	char s[30];
	int i=0,len=0,j,flag=1;
	printf("Enter String : ");
	gets(s);
	printf("%s\n",s);
	
	permutation(s,0);
	
	return 0;
}
