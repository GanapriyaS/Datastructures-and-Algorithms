// R. Butterfly
// time limit per test1 second
// memory limit per test256 megabytes
// You are given a positive integer n.

// Print a butterfly pattern consisting of 2n−1 rows.

// Input
// The input contains a single integer n (1≤n≤200)


// Output
// Print the pattern, as given in the example.

// Examples
// Input
// 6
// Output
// *          *
// **        **
// ***      ***
// ****    ****
// *****  *****
// ************
// *****  *****
// ****    ****
// ***      ***
// **        **
// *          *
// Input
// 4
// Output
// *      *
// **    **
// ***  ***
// ********
// ***  ***
// **    **
// *      *


#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	//Crown
    for(int i=1;i<=n;i++){
     for(int j=1;j<=i;j++){
         cout << "*";
     }
      for(int j=1;j<=2 * (n-i);j++){
         cout << " ";
     }
      for(int j=1;j<=i;j++){
         cout << "*";
     }
      cout << endl;
    }
     //Inverted Crown
    for(int i=n-1;i>=1;i--){
     for(int j=1;j<=i;j++){
         cout << "*";
     }
      for(int j=1;j<=2 * (n-i);j++){
         cout << " ";
     }
      for(int j=1;j<=i;j++){
         cout << "*";
     }
        cout << endl;
    }
}

// #include <iostream>
// using namespace std;
// int main() {
//    int n;
//    cin >> n;
   
//    for(int i=0;i<n;i++){
       
//        for(int j=0 ; j<2*n;j++){
//           if(j<=i || j>=2*n-i-1)
//            cout<<"*";
//           else
//           cout << " ";
//        }
//        cout << "\n";
//    }
   
   
//     for(int i=0;i<n-1;i++){
       
//        for(int j=0 ; j<2*n;j++){
//           if(j<n-i-1 || j>n+i)
//            cout<<"*";
//           else
//           cout << " ";
//        }
//        cout << "\n";
//    }
   
//     return 0;
// }