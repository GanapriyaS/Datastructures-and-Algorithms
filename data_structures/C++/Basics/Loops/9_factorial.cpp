// I. Factorial
// time limit per test1 second
// memory limit per test256 megabytes
// You are given an integer N
// .

// Find the factorial of N
//  by writing a function that takes N
//  as a parameter and returns N!
// , where:
// N!=1×2×3×⋯×N

// Input
// The first line contains an integer N (0≤N≤20).

// Output
// Print the value of N!

// Examples
// Input
// 5
// Output
// 120
// Input
// 7
// Output
// 5040
// Note
// By definition, 0!=1.
// The constraint N≤20 ensures the answer fits in a 64-bit integer.



#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    long long t = 1;
 
    for(int i = 1; i <= n; i++){
        t = t * i;
    }
 
    cout << t;
 
    return 0;
}
