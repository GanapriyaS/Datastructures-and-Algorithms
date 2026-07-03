// xn
// time limit per test1 second
// memory limit per test256 megabytes
// You are given two integers x and n.
// Input
// The first line contains two integers x and n (−10≤x≤10, 0≤n≤20).

// Output
// Print the value of xn.

// Example
// Input
// 2 5
// Output
// 32
// Note
// For any x, x0=1. The constraints ensure the answer fits in a 64-bit integer.


#include <iostream>
using namespace std;
 
int main() {
    int x,n;
    cin >> x >> n;
    long long t=1;
    for(int i=1;i<=n;i++){
        t=t*x;
    }
    
    cout <<t;
    return 0;
}
