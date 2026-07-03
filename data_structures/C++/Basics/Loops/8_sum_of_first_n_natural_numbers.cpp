// H. Sum of First N Natural Numbers
// time limit per test1 second
// memory limit per test256 megabytes
// You are given an integer N. Find the sum: 1+2+3+⋯+N

// Input
// The first line contains an integer N (1≤N≤106).

// Output
// Print a single integer — the sum of the first N natural numbers.

// Examples
// Input
// 5
// Output
// 15
// Input
// 10
// Output
// 55
// Note
// The first 5 natural numbers are 1,2,3,4, and 5, and their sum is 15.



#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    long long t=0;
    for(int i=1;i<=n;i++){
        t=t+i;
    }
    
    cout<<t;
 
    return 0;
}
 