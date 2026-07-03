// H. Numbered Traingle
// time limit per test1 second
// memory limit per test256 megabytes
// You are given a positive integer n.

// Print a pyramid of n rows, where the i-th row (1≤i≤n) consists of the digit i.

// Input
// The input contains a single integer n (1≤n≤200).

// Output
// Print the numbered pyramid with n rows.

// Examples
// Input
// 5
// Output
// 1
// 22
// 333
// 4444
// 55555
// Input
// 6
// Output
// 1
// 22
// 333
// 4444
// 55555
// 666666


#include <iostream>
using namespace std;
int main() {
   int n;
   cin >> n ;
   for(int i=0;i<n;i++){
       for(int j=0;j<=i;j++){
           
       cout<<i+1;
       }
          cout<<"\n";
   }
 
    return 0;
}