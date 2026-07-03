// E. Print Table of 5
// time limit per test1 second
// memory limit per test256 megabytes
// Your task is to print the multiplication table of the 5.

// Input
// There is no input for this problem.

// Output
// Print the table of 5 in the format as shown in the example.

// Example
// Input
// There is no input.
// Output
// 5 * 1 = 5
// 5 * 2 = 10
// 5 * 3 = 15
// 5 * 4 = 20
// 5 * 5 = 25
// 5 * 6 = 30
// 5 * 7 = 35
// 5 * 8 = 40
// 5 * 9 = 45
// 5 * 10 = 50


#include<iostream>
using namespace std;
 
 
int main(){
    int n=5;
    for(int i=1; i<=10; i++){
        cout << n << " * " << i << " = "<< n*i << "\n";
    }
 
    return 0;
}