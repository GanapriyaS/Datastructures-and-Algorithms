// M. Reverse Number and Store in a Variable
// time limit per test1 second
// memory limit per test256 megabytes
// You are given a non-negative integer N

// Reverse the digits of N and store the result in a variable.

// Input
// The first line contains a non-negative integer N (0≤N≤109).

// Output
// Print the result.

// Examples
// Input
// 1234
// Output
// 4321
// Input
// 1950
// Output
// 591


#include <iostream>
using namespace std;
 
int main() {
    long long n;
    cin>>n;
    long long sum=0;
    while(n > 0){
        int last = n%10;
        sum+=last;
        n=n/10;
    }
 
    cout<<sum;     
 
    return 0;
}