// Q. Crown
// time limit per test1 second
// memory limit per test256 megabytes
// You are given a positive integer n.

// Print a crown pattern consisting of n rows.

// Input
// The input contains a single integer n (1≤n≤200).

// Output
// Print the pattern, as given in the example.

// Examples
// Input
// 7
// Output
// *            *
// **          **
// ***        ***
// ****      ****
// *****    *****
// ******  ******
// **************
// Input
// 4
// Output
// *      *
// **    **
// ***  ***
// ********

#include <iostream>
using namespace std;
int main() {
   int n;
   cin >> n;
   
   for(int i=0;i<n;i++){
       
       for(int j=0 ; j<2*n;j++){
          if(j<=i || j>=2*n-i-1)
           cout<<"*";
          else
          cout << " ";
       }
       cout << "\n";
   }
   
    return 0;
}