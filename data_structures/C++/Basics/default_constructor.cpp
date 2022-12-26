#include<iostream>
using namespace std;

class Sum{
  int a,b,c;
  public: 
    Sum(int a,int b, int c=0){
      this->a=a;
      this->b=b;
      this->c=c;
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
    r.sum();
    r1.sum();
    r2.sum();
    return 0;
}