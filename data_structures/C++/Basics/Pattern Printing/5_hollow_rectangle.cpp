// E. Hollow Rectangle
// time limit per test1 second
// memory limit per test256 megabytes
// Given two integers n and m, print a hollow rectangle of dimensions n×m.

// Input
// The only line contains two integers n and m (1≤n,m≤100).

// Output
// Print the pattern.

// Examples
// Input
// 5 5
// Output
// *****
// *   *
// *   *
// *   *
// *****
// Input
// 6 9
// Output
// *********
// *       *
// *       *
// *       *
// *       *
// *********


#include <iostream>
using namespace std;
int main() {
   int n,m;
   cin >> n >> m ;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(i==0 || j==0 || i==n-1 || j==m-1){
       cout<<"*";}else{
           cout<<" ";
       }
       }
          cout<<"\n";
   }
 
    return 0;
}