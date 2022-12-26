#include<iostream>
using namespace std;
int count=0;
class alpha{
public:
alpha(){
    count++;
    cout<<"\nObject count created : "<<count;
}
~alpha(){
cout<<"\nObject count destroyed : "<<count;
count--;
}
};

int main(){
    cout<<"Enter main :";
    alpha a1,a2,a3,a4;
    {   
        cout<<"\nEnter block1 :";
        alpha a5;
    }
    {   
        cout<<"\nEnter block2 :";
        alpha a6;
    }
    cout<<"\nReenter main :";
    return 0;
}