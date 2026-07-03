// E. Print All Uppercase Alphabets
// time limit per test1 second
// memory limit per test256 megabytes
// Print all uppercase English alphabets from A to Z using loops.

// Input
// There is no input for this problem.

// Output
// Print all uppercase English alphabets from A to Z, separated by spaces.

// Example
// Input
// There is no input.
// Output
// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z



#include <iostream>
using namespace std;
 
int main() {
    for(int i=65;i<=90;i++){
        cout<<char(i)<<" ";
    }
 
    return 0;
}