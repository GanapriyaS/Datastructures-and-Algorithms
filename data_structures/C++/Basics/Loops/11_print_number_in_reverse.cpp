// K. Print Number in Reverse
// time limit per test1 s.
// memory limit per test256 MB
// Given an integer N, print the digits of N in reverse order.

// Input
// A single integer N (0≤N≤1018).

// Output
// Print the number formed by reversing the digits of N
// .

// Examples
// Input
// 12349
// Output
// 94321
// Input
// 1950
// Output
// 0591



// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
 
int main() {
    long long n;
    cin>>n;
    if(n==0) {
        cout << n;
        return 0;
    }
    string reverse="";
    while(n > 0){
        int last = n%10;
        reverse = reverse + to_string(last);
        n=n/10;
    }
    
    cout<<reverse;
 
    return 0;
}
 