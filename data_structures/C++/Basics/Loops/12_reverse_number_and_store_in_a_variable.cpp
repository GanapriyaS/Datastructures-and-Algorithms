// L. Sum Of Digits
// time limit per test1 second
// memory limit per test256 megabytes
// Given an integer N, find the sum of its digits.

// Input
// A single integer N (0≤N≤1018).

// Output
// Print the sum of digits of N.

// Example
// Input
// 1234
// Output
// 10



#include <iostream>
using namespace std;
 
int main() {
    long long n;
    cin>>n;
    long long reverse=0;
    while(n > 0){
        int last = n%10;
        reverse = (reverse *10)+ last;
        n=n/10;
    }
 
    cout<<reverse;
 
    return 0;
}