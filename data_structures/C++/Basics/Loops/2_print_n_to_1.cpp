// B. Print N to 1
// time limit per test1 second
// memory limit per test256 megabytes
// You are given an integer N
// Print all integers from N to 1 in decreasing order.

// Input
// Print N integers from N to 1, separated by spaces.

// Output
// Print N integers from N to 1, separated by spaces.

// Examples
// Input
// 5
// Output
// 5 4 3 2 1
// Input
// 4
// Output
// 4 3 2 1


#include <iostream>
using namespace std;
 
int main() {
    int a;
    cin>>a;
 for(int i=a;i>0;i--){
     cout<<i<<" ";
 }
 
    return 0;
}