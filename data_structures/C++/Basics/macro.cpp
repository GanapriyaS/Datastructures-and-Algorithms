#include<iostream>
using namespace std;

#define MAX(a,b,c) (a>b?(a>c?a:c):(b>c?b:c))
inline int max(int a,int b,int c){ return a>b?(a>c?a:c):(b>c?b:c);}

int main ()
{   
    int a,b,c;
    cout<<"Enter a,b,c : ";
    cin>>a>>b>>c;
    cout<<"Maximum : "<<max(a,b,c)<<endl;
    return 0;
}