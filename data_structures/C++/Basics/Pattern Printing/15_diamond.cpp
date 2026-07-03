// O. Diamond
// time limit per test1 second
// memory limit per test256 megabytes
// You are given a positive integer n.

// Print a diamond pattern consisting of 2n−1 rows.
//  The first n rows form the upper triangle.
//  The next n−1 rows form the lower triangle.

// Input
// The input contains a single integer n (1≤n≤200).

// Output
// Print the diamond consisting of 2n−1 rows.

// Examples
// Input
// 3
// Output
//   * 
//  * * 
// * * * 
//  * * 
//   * 
// Input
// 5
// Output
//     * 
//    * * 
//   * * * 
//  * * * * 
// * * * * * 
//  * * * * 
//   * * * 
//    * * 
//     * 

#include <iostream>
using namespace std;
int main() {
   int n;
   cin >> n;
   
   for(int i=0;i<n;i++){
       for(int j=0;j<n-i-1;j++){
           cout<<" ";
       }
       for(int j=0 ; j<=2*i;j++){
          if(j%2==0)
           cout<<"*";
          else
          cout << " ";
       }
       cout << "\n";
   }
   
   for(int i=1;i<n;i++){
       for(int j=0;j<i;j++){
           cout<<" ";
       }
       for(int j=0 ; j<2*n-2*i-1;j++){
          if(j%2==0)
           cout<<"*";
          else
          cout << " ";
       }
       cout << "\n";
   }
   
    return 0;
}