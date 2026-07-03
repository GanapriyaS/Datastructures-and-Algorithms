// N. Max and Min of 2 Numbers
// time limit per test1 second
// memory limit per test256 megabytes
// You are given two integers A and B. Your task is to find the minimum and maximum among them.

// Input
// A single line containing two integers A and B (1≤A,B≤109).

// Output
// Print two lines:

// Min = X
// Max = Y
// where X
//  is the minimum value and Y
//  is the maximum value.

// Example
// Input
// 12 9
// Output
// Min = 9
// Max = 12

#include<iostream>
using namespace std;
 
 
int main(){
    int m,n;
    cin >> m >> n;
    cout << "Min = " << (m > n ? n:m) << "\n";
    cout << "Max = " << (m > n ? m : n) << "\n";
 
    return 0;
}