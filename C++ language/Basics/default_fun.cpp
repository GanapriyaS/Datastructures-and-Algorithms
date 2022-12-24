#include<iostream>
using namespace std;

int main(){

    void print(string s="***HELLO***",int len=15);
    float value(float p,int n,float r=0.15);
    print();
    float amount=value(5000.08,5);
    cout<<amount<<endl;
    print("###HIII###");
    return 0;
}

float value(float p,int n,float r){
    int y=1;
    float sum=p;
    while(y <= n){
        sum=sum*(1+r);
        y=y+1;
    }
    return(sum);
}

void print(string s,int len)
{
    for(int i=0;i<=len;i++) cout<<s[i];
    cout<<endl;
}