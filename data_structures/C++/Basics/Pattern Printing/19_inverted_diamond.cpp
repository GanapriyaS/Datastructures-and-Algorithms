// S. Inverted Diamond
// time limit per test1 second
// memory limit per test256 megabytes
// You are given a positive integer n.

// Print a inverted diamond pattern consisting of 2n−1 rows.

// Input
// The input contains a single integer n (1≤n≤200).

// Output
// Print the pattern, as given in the example.

// Examples
// Input
// 5
// Output
// ***** *****
// ****   ****
// ***     ***
// **       **
// *         *
// **       **
// ***     ***
// ****   ****
// ***** *****

// Input
// 3
// Output
// *** ***
// **   **
// *     *
// **   **
// *** ***





// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
   int n;
   cin >> n;
   
   for(int i=0;i<n;i++){
       for(int j=0;j<n-i;j++){
           cout<<"*";
       }
       for(int j=0 ; j<=2*i;j++){
          
          cout << " ";
       }
       for(int j=0;j<n-i;j++){
           cout<<"*";
       }
       cout << "\n";
   }
   
   for(int i=1;i<n;i++){
       for(int j=0;j<=i;j++){
           cout<<"*";
       }
       for(int j=0 ; j<2*n-2*i-1;j++){
          cout << " ";
       }
       for(int j=0;j<=i;j++){
           cout<<"*";
       }
       cout << "\n";
   }
   
    return 0;
}