// P. Student Performance Evaluation
// time limit per test1 second
// memory limit per test256 megabytes
// You are given the marks obtained by a student. Based on the marks, display an appropriate performance message according to the following rules:

// If marks are greater than 90
// , print Excellent
// Else if marks are greater than 80
//  and less than or equal to 90
// , print Good
// Else if marks are greater than 70
//  and less than or equal to 80
// , print Fair
// Else if marks are greater than 60
//  and less than or equal to 70
// , print Meets Expectations
// Else (marks less than or equal to 60
// ), print Below Par
// Input
// A single integer marks (0≤marks≤100)

// Output
// Print a single line containing the performance message corresponding to the given marks.

// Examples
// Input
// 85
// Output
// Good
// Input
// 99
// Output
// Excellent

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
 
int main() {
    int a;
    cin>>a;
    
    if(a<=60){
        cout << "Below Par";
    }else if(a<=70){
        cout <<  "Meets Expectations";
    }else if(a<=80){
        cout << "Fair";
        
    }else if(a<=90){
        cout << "Good";
    }else{
        cout << "Excellent";
    }
 
 
    return 0;
}