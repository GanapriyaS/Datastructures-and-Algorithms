// G. Count Numbers
// time limit per test1 second
// memory limit per test256 megabytes
// You are given an integer N
//  followed by N
//  integers. Count how many of the given numbers are:

// Positive
// Negative
// Even
// Odd
// Input
// The first line contains an integer N (1≤N≤105).

// The second line contains N integers (−109≤Ai≤109).

// Output
// Print four integers in the following order:

// Number of positive integers
// Number of negative integers
// Number of even integers
// Number of odd integers
// Example
// Input
// 5
// -2 0 3 7 -5
// Output
// 2
// 2
// 2
// 3
// Note
// Zero is neither positive nor negative.
// Zero is considered an even number.

#include <iostream>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    int a[n];
    int pos=0;
    int neg=0;
    int even=0;
    int odd=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i] >0) 
        pos+=1;
        else if(a[i]<0) 
        neg+=1;
        
        if(a[i]%2==0)
        even+=1;
        else
        odd+=1;
    }
    
    cout<<pos<<"\n";
    cout<<neg<<"\n";
    cout<<even<<"\n";
    cout<<odd<<"\n";
 
    return 0;
}
 