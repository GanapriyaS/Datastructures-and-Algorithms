#include<iostream>
using namespace std;

class Sum{
  int a,b,c;
  public: 
  Sum(){a=b=c=1;}
    Sum(int a,int b, int c=0){
      this->a=a;
      this->b=b;
      this->c=c;
    }
    Sum(Sum &s){
        a=s.a;
        b=s.b;
        c=s.c;
    }
  
    void sum(){
        int d=a+b+c;
        cout<<"Sum of the numbers : "<< d<<"\n";
    }
};


int main(){
    Sum r;
    Sum r1(10,20);
    Sum r2(20,10,30);
    Sum r3(r2);
    Sum r4=r1;
    r.sum();
    r1.sum();
    r2.sum();
    r3.sum();
    r4.sum();
    return 0;
}