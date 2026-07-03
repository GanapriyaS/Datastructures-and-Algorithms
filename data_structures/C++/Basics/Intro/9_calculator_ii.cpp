// H2. Calculator - II
// time limit per test1 second
// memory limit per test256 megabytes
// You are given two integers N and M. Your task is to compute and print the results of the following operations:

// N+M
// N−M
// N×M
// N÷M(integer division)
// NmodM
// Input
// Two integers N and M
// , each given on a separate line (1≤N,M≤109)

// Output
// Print five results in the following format as shown in the example.

// Example
// Input
// 1000000000
// 1000000000
// Output
// 1000000000 + 1000000000 = 2000000000

// 1000000000 - 1000000000 = 0

// 1000000000 * 1000000000 = 1000000000000000000

// 1000000000 / 1000000000 = 1

// 1000000000 % 1000000000 = 0



#include<iostream>
using namespace std;
 
 
int main(){
    long long m,n;
    cin >> m >> n;
    cout << m <<" + " << n<<" = "<<m+n <<"\n\n";
    cout << m <<" - " << n<<" = "<<m-n <<"\n\n";
    cout << m <<" * " << n<<" = "<<m*n <<"\n\n";
    cout << m <<" / " << n<<" = "<<m/n <<"\n\n";
    cout << m <<" % " << n<<" = "<<m%n <<"\n\n";
    return 0;
}