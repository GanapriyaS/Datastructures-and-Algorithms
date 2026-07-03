// J. Vertical Traingle
// time limit per test1 second
// memory limit per test256 megabytes
// You are given a positive integer n.

// Print a triangle of 2n−1 rows.

// Input
// The input contains a single integer n (1≤n≤200).

// Output
// Print the vertical triangle of stars, as shown in the example.

// Examples
// Input
// 4
// Output
// * 
// * * 
// * * * 
// * * * * 
// * * * 
// * * 
// * 
// Input
// 7
// Output
// * 
// * * 
// * * * 
// * * * * 
// * * * * * 
// * * * * * * 
// * * * * * * * 
// * * * * * * 
// * * * * * 
// * * * * 
// * * * 
// * * 
// * 

#include <iostream>
using namespace std;
int main() {
   int n;
   cin >> n ;
   for(int i=0;i<n;i++){
       for(int j=0;j<=i;j++){
           
       cout<<"* ";
       }
          cout<<"\n";
   }
    for(int i=0;i<n-1;i++){
       for(int j=i;j<n-1;j++){
           
       cout<<"* ";
       }
          cout<<"\n";
   }
 
    return 0;
}