// K. Factor
// time limit per test1 second
// memory limit per test256 megabytes
// You are given two integers N
//  and F. Your task is to check whether F is a factor of N.

// A number F is said to be a factor of N if N is divisible by F.

// Input
// A single line containing two integers N and F (1≤N,F≤109)


// Output
// Print:
// Yes if F is a factor of N
// No otherwise

// Example
// Input
// 36 6
// Output
// Yes


#include<iostream>
using namespace std;
 
 
int main(){
    int m,n;
    cin >> m >> n;
    if(m%n==0)
    cout << "Yes";
    else
    cout << "No";
    return 0;
}
