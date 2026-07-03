// C. Triangle
// time limit per test1 second
// memory limit per test256 megabytes
// Your task is to print a right-angled triangle pattern using asterisks (*).

// Input
// There is no input for this problem.

// Output
// Print the following pattern exactly as shown:


// *****
// ****
// ***
// **
// *

#include<iostream>
using namespace std;
 
 
int main(){
    for(int i=5; i>0; i--){
        for(int j=0;j<i;j++){
            cout << "*";
        }
        cout << "\n";
    }
 
    return 0;
}