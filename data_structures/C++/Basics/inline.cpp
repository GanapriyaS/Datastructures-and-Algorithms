#include<iostream>
using namespace std;

inline float mul(float a,float b){ return a*b;}
inline double div(double a,double b){ return a/b;}

int main(){
   float a=4.9,b=6.75;
   cout<<mul(a,b)<<endl;
   cout<<div(a,b)<<endl;
   return 0;
}