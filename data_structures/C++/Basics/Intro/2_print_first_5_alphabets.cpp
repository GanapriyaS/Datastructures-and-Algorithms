// B. Print First 5 Alphabets
// time limit per test 1 second
// memory limit per test 256 megabytes
// Your task is to print the first five letters of the English alphabet.

// Input
// There is no input for this problem.

// Output
// Print the first five uppercase English letters, one per line.

// Example
// Input
// There is no input.
// Output
// A
// B
// C
// D
// E

#include<iostream>
using namespace std;
 
 
int main(){
    char l[5] = {'A','B','C','D','E'};
    for(int i=0;i<5;i++){
        cout<<l[i]<<"\n";
    }
 
    return 0;
}