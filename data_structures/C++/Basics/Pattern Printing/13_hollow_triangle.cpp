// M. Hollow Triangle
// time limit per test1 second
// memory limit per test256 megabytes
// You are given a positive integer n.

// Print a hollow triangle pattern consisting of n rows.

// Input
// The input contains a single integer n (1≤n≤2⋅103).

// Output
// Print n lines, as given in the example.

// Examples
// Input
// 6
// Output
//      * 
//     * * 
//    *   * 
//   *     * 
//  *       * 
// * * * * * * 
// Input
// 4
// Output
//    * 
//   * * 
//  *   * 
// * * * * 


// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n ;
  for(int i=0;i<n;i++){
      for(int j=i;j<n-1;j++){
         
      cout << " ";
      }
       
        for(int j=0;j<=2*i;j++){
          if(j==0 || j==2*i || (i==n-1 && j%2==0))
      cout<<"*";
      else
      cout<<" ";
      }
          cout<<"\n";
  }
 
    return 0;
}
 