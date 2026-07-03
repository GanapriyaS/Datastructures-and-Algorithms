// O. Max and Min of 3 Numbers
// time limit per test1 second
// memory limit per test256 megabytes
// You are given three integers A, B, and C. Your task is to find the minimum and maximum among them.

// Input
// A single line containing three integers A, B, and C (1≤A,B,C≤109).

// Output
// Print two lines:

// Min = X
// Max = Y
// where X
//  is the minimum value and Y
//  is the maximum value.

// Example
// Input
// 12 9 15
// Output
// Min = 9
// Max = 15


#include <iostream>
using namespace std;
 
int main() {
    int a,b,c;
    cin>>a>>b>>c;
    cout << "Min = "<< (a>b? (b>c?c:b):(a>c?c:a)) << "\n";
    // if(a>b){
    //     if(a>c){
    //         cout <<"Max = "<<a;
    //     }else{
    //          cout <<"Max = "<<c;
    //     }
        
    // }else{
    //      if(b>c){
    //         cout <<"Max = "<<b;
    //     }else{
    //          cout <<"Max = "<<c;
    //     }
        
    // }
    
    
    if(a>b && a>c){
       cout <<"Max = "<<a;
    }else if(a<b && b>c){
         cout <<"Max = "<<b;
    }else{
    cout <<"Max = "<<c;
    }
 
    return 0;
}