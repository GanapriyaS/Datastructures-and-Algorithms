// J. Even or Odd
// time limit per test1 second
// memory limit per test256 megabytes
// You are given an integer N. Your task is to determine whether the number is even or odd.

// Input
// A single integer N (1≤N≤109)

// Output
// Even if N is even
// Odd if N is odd

// Examples
// Input
// 20
// Output
// Even

// Input
// 3
// Output
// Odd



#include<iostream>
using namespace std;
 
 
int main(){
    int m;
    cin >> m;
    if(m%2==0)
    cout << "Even";
    else
    cout << "Odd";
    return 0;
}