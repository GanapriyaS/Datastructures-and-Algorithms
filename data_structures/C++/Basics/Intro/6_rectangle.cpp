// ProblemsSubmit CodeMy SubmissionsStatusStandingsCustom Invocation
// F. Rectangle
// time limit per test1 second
// memory limit per test256 megabytes
// You are given the length and breadth of a rectangle. Your task is to calculate its area and perimeter.

// The formulas are:

// Area =
//  length ×
//  breadth
// Perimeter =
//  2×(length+breadth)
// Input
// A single line containing two integers length and breadth (1≤length,breadth≤1000)
// .

// Output
// You are given the length and breadth of a rectangle. Your task is to calculate its area and perimeter.

// The formulas are:

// Area =
//  length ×
//  breadth
// Perimeter =
//  2×(length+breadth)

// Example
// Input
// 5 7
// Output
// Area = 35
// Perimeter = 24

#include<iostream>
using namespace std;
 
 
int main(){
    int l,b;
    cin >> l;
    cin >> b;
    cout << "Area = " << l*b <<"\n";
    cout << "Perimeter = " << 2*(l+b);
 
    return 0;
}