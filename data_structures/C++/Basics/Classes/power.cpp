#include<iostream>
using namespace std;
#include<cmath>

double power(double m,int n=2){
    // double result=1;
    // if(n==0) return 1.0;
    // while (n != 0) {
    //     result *= m;
    //     --n;
    // }
    // return result;
    return pow(m,n);
}
int main ()
{   
    double m;
    int n;
    cout<<"Enter base and exponent : ";
    cin>>m>>n;
    cout<<"Power : "<<power(m,n)<<endl;
    return 0;
}