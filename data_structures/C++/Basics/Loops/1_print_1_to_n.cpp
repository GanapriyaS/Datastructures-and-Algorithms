// A. Print 1 to N
// time limit per test1 second
// memory limit per test256 megabytes
// You are given a positive integer n

// Print the integers from 1 to n (inclusive), each on a separate line.

// Input
// The input contains a single integer n (1≤n≤2⋅105)

// Output
// Print n lines. On the i-th line, output the integer i (1≤i≤n)


// Examples
// Input
// 5
// Output
// 1
// 2
// 3
// 4
// 5
// Input
// 2
// Output
// 1
// 2



#include <iostream>
using namespace std;
 
int main() {
    int a;
    cin>>a;
 for(int i=1;i<=a;i++){
     cout<<i<<"\n";
 }
 
    return 0;
}
