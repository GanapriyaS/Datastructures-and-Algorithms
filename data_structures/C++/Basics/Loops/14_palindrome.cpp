// N. Palindrome
// time limit per test1 s.
// memory limit per test256 MB
// You are given a non-negative integer N. Check whether N is a palindrome or not.

// A number is called a palindrome if it reads the same forwards and backwards.

// Input
// The first line contains a non-negative integer N (0≤N≤1018).

// Output
// Print YES if the number is a palindrome, otherwise print NO.

// Examples
// Input
// 121
// Output
// YES
// Input
// 1950
// Output
// NO


#include<iostream>
using namespace std;
 
 
long long Solution3(long long s)
{
    long long n=s;
	long long reverse=0;
    while(n > 0){
        int last = n%10;
        reverse = (reverse *10)+ last;
        n=n/10;
    }
    if(s==reverse){
	    return 1;
    }
	return 0;
}
 
 
int main(){
 
	long long a;
	cin>>a;
	if(Solution3(a)) cout<<"YES";
	else cout<<"NO";
 
    return 0;
}
