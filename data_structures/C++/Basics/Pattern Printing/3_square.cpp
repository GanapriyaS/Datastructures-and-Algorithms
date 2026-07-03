// C. Square
// time limit per test1 second
// memory limit per test256 megabytes
// You are given a positive integer n.

// Print an n×n square of stars.

// Input
// The input contains a single integer n (1≤n≤2⋅103)

// Output
// Print n lines, as given in the example.

// Examples
// Input
// 5
// Output
// *****
// *****
// *****
// *****
// *****
// Input
// 2
// Output
// **
// **


#include <iostream>
using namespace std;
int main() {
   int n;
   cin >> n ;
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
       cout<<"*";
       }
          cout<<"\n";
   }
 
    return 0;
}