// I. Binary Pyramid
// time limit per test1 second
// memory limit per test256 megabytes
// You are given a positive integer n.

// Print a pyramid of n rows. The first row contains a single '0'. From the second row onward, the digits alternate between '1' and '0'.

// Input
// The input contains a single integer n (1≤n≤200).

// Output
// Print the binary pyramid with n rows.

// Examples
// Input
// 6
// Output
// 0
// 10
// 010
// 1010
// 01010
// 101010
// Input
// 2
// Output
// 0
// 10

#include <iostream>
using namespace std;
int main() {
   int n;
   cin >> n ;
   for(int i=1;i<=n;i++){
       for(int j=1;j<=i;j++){
           if((i+j)%2==0){
               cout << "0";
           }else{
       cout<<"1";
           }
       }
          cout<<"\n";
   }
 
    return 0;
}