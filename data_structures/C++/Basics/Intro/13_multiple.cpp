// L. Multiple
// time limit per test1 second
// memory limit per test256 megabytes
// You are given two integers N and M. Your task is to check whether M is a multiple of N.

// A number M is said to be a multiple of N if M is divisible by N.

// Input
// A single line containing two integers N and M (1≤N,M≤109)

// Output
// Print:

// Yes if M is a multiple of N
// No otherwise

// Example
// Input
// 6 36
// Output
// Yes

#include<iostream>
using namespace std;
 
 
int main(){
    int m,n;
    cin >> m >> n;
    if(n%m==0)
    cout << "Yes";
    else
    cout << "No";
    return 0;
}
