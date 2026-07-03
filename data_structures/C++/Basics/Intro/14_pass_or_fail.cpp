// M. Pass or Fail
// time limit per test1 second
// memory limit per test256 megabytes
// You are given the marks obtained by a student. Your task is to check whether the student has passed or failed.

// A student is considered to have passed if the marks obtained are at least 35.

// Input
// A single integer marks (0≤marks≤100)

// Output
// Print:

// Pass if the student has passed
// Fail otherwise
// Examples
// Input
// 36
// Output
// Pass
// Input
// 20
// Output
// Fail


#include<iostream>
using namespace std;
 
 
int main(){
    int m;
    cin >> m;
    if(m>=35)
    cout << "Pass";
    else
    cout << "Fail";
    return 0;
}