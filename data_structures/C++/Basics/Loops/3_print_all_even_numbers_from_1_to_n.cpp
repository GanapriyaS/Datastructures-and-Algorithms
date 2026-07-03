// C. Print All Even Numbers from 1 to N
// time limit per test1 second
// memory limit per test256 megabytes
// You are given an integer N. Print all even numbers between 1 and N (inclusive) in increasing order.

// Input
// The first line contains an integer N (1≤N≤105).

// Output
// Print all even numbers between 1 and N, separated by spaces.

// If there is no even number in the given range, print nothing.

// Example
// Input
// 10
// Output
// 2 4 6 8 10
// Note
// An integer is even if it is divisible by 2



#include <iostream>
using namespace std;
 
int main() {
    int a;
    cin>>a;
    for(int i=1;i*2<=a;i++){
        cout<<i*2<<" ";
    }
 
    return 0;
}
