// D. Print Z
// time limit per test1 second
// memory limit per test256 megabytes
// Your task is to print the letter Z using asterisks (*) as shown below.

// Input
// There is no input for this problem.

// Output
// Print the following pattern exactly as shown:


// *****
//    *
//   *
//  *
// *****


#include<iostream>
using namespace std;
 
 
int main(){
    int n=5;
    for(int i=0; i<n; i++){
        for(int j=0;j<n;j++){
            if(i==0 || i==n-1 || j== n-i ){
                cout << "*";
            }else{
                cout << " ";
            }
        }
        cout << "\n";
    }
 
    return 0;
}
