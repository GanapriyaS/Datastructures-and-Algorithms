// A. 2-Stars
// time limit per test1 second
// memory limit per test256 megabytes
// You are given a positive integer n.

// Print a pattern consisting of n rows, where each row contains exactly two stars ('**').

// Input
// The input contains a single integer n (1≤n≤2⋅105)

// Output
// Print n lines. Each line must contain exactly two stars ('**').

// Examples
// Input
// 5
// Output
// **
// **
// **
// **
// **
// Input
// 3
// Output
// **
// **
// **


#include <iostream>
using namespace std;
int main() {
   int n;
   cin >> n;
   for(int i=0;i<n;i++){
       cout<<"**\n";
   }
 
    return 0;
}
