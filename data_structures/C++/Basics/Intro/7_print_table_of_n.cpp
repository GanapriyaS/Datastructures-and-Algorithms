// G. Print Table of N
// time limit per test1 second
// memory limit per test256 megabytes
// You are given an integer N
// . Your task is to print the multiplication table of N
//  from 1
//  to 10
// .

// Input
// A single integer N
//  (1≤N≤100)
// .

// Output
// Print the table of N
//  in the format shown in the example below.

// Example
// Input
// 6
// Output
// 6 * 1 = 6
// 6 * 2 = 12
// 6 * 3 = 18
// 6 * 4 = 24
// 6 * 5 = 30
// 6 * 6 = 36
// 6 * 7 = 42
// 6 * 8 = 48
// 6 * 9 = 54
// 6 * 10 = 60



#include<iostream>
using namespace std;
 
 
int main(){
    int n;
    cin >> n;
    for(int i=1; i<=10; i++){
        cout << n << " * " << i << " = "<< n*i << "\n";
    }
 
    return 0;
}