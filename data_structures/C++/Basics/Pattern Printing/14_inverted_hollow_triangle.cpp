
// N. Inverted Hollow Triangle
// time limit per test1 second
// memory limit per test256 megabytes
// You are given a positive integer n.

// Print a inverted hollow triangle pattern consisting of n rows.

// Input
// The input contains a single integer n (1≤n≤2⋅103).

// Output
// Print n lines, as given in the example.

// Examples
// Input
// 7
// Output
// * * * * * * * 
//  *         * 
//   *       * 
//    *     * 
//     *   * 
//      * * 
//       * 
// Input
// 3
// Output
// * * * 
//  * * 
//   * 


#include <iostream>
using namespace std;
int main() {
  int n;
  cin >> n ;
  for(int i=0;i<n;i++){
      for(int j=0;j<i;j++){
      cout << "";
      }
        for(int j=i;j<2*n-1;j++){
          if(j==i || j==(2*n)-i-2|| (i==0 && j%2==0))
      cout<<"*";
      else
      cout<<" ";
      }
      cout<<"\n";
  }
    return 0;
}
 