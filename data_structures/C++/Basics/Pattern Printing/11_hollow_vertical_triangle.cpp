// K. Hollow Vertical Triangle
// time limit per test1 s.
// memory limit per test256 MB
// You are given a positive integer n.

// Print a hollow triangle of 2n−1 rows.

// Input
// The input contains a single integer n (1≤n≤200).

// Output
// Print the inverted vertical triangle of stars, as shown in the example.

// Examples
// Input
// 5
// Output
// * 
// * * 
// *   * 
// *     * 
// *       * 
// *     * 
// *   * 
// * * 
// * 
// Input
// 3
// Output
// * 
// * * 
// *   * 
// * * 
// * 

#include <iostream>
using namespace std;
int main() {
   int n;
   cin >> n ;
   for(int i=0;i<n;i++){
       for(int j=0;j<=i;j++){
           if(j==0 || j==i)
       cout<<"* ";
       else 
       cout << " ";
       }
          cout<<"\n";
   }
    for(int i=0;i<n-1;i++){
       for(int j=i;j<n-1;j++){
           
         if(j==n-2 || j==i)
       cout<<"* ";
       else 
       cout << " ";
       }
          cout<<"\n";
   }
 
    return 0;
}
