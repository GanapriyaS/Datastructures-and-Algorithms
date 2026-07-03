// I. Add Last Digits
// time limit per test1 second
// memory limit per test256 megabytes
// You are given two integers N
//  and M. Your task is to find the sum of the last digits of N
//  and M

// Input
// A single line containing two integers N and M (1≤N,M≤1000)

// Output
// Print a single integer — the sum of the last digits of N and M

// Example
// Input
// 169 125
// Output
// 14

#include<iostream>
using namespace std;
 
 
int main(){
    int m,n;
    cin >> m >> n;
    cout << (m % 10) + (n%10);
    return 0;
}
