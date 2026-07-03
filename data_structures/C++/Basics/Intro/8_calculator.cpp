// H1. Calculator
// time limit per test1 second
// memory limit per test256 megabytes
// You are given two integers N and M
// Your task is to compute and print the results of the following operations:

// N+M
// N−M
// N×M
// N÷M (integer division)
// NmodM
// Input
// A single line containing two integers N and M
// (1≤N,M≤1000)

// Output
// Print five lines in the format as shown in the example.

// Example
// Input
// 6 4
// Output
// 6 + 4 = 10
// 6 - 4 = 2
// 6 * 4 = 24
// 6 / 4 = 1
// 6 % 4 = 2

#include<iostream>
using namespace std;
 
 
int main(){
    int m,n;
    cin >> m >> n;
    cout << m <<" + " << n<<" = "<<m+n <<"\n";
    cout << m <<" - " << n<<" = "<<m-n <<"\n";
    cout << m <<" * " << n<<" = "<<m*n <<"\n";
    cout << m <<" / " << n<<" = "<<m/n <<"\n";
    cout << m <<" % " << n<<" = "<<m%n <<"\n";
    return 0;
}