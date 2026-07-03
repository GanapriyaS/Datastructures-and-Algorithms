// D. Print from L to R
// time limit per test1 second
// memory limit per test256 megabytes
// You are given two integers L
//  and R
// . Print all integers from L
//  to R in increasing order.

// Input
// The first line contains two integers L and R (−105≤L≤R≤105).

// Output
// Print all integers from L to R, separated by spaces.

// Example
// Input
// 3 7
// Output
// 3 4 5 6 7

#include <iostream>
using namespace std;
 
int main() {
    int a,b;
    cin>>a>>b;
    for(int i=a;i<=b;i++){
        cout<<i<<" ";
    }
 
    return 0;
}
