// F. Pyramid
// time limit per test1 second
// memory limit per test256 megabytes
// You are given a positive integer n.

// Print a pyramid pattern consisting of n rows.

// Input
// The input contains a single integer n (1≤n≤2⋅103)

// Output
// Print n lines, as given in the example.

// Examples
// Input
// 5
// Output
// *
// **
// ***
// ****
// *****
// Input
// 6
// Output
// *
// **
// ***
// ****
// *****
// ******
// Input
// 7
// Output
// *
// **
// ***
// ****
// *****
// ******
// *******

using namespace std;
int main() {
   int n;
   cin >> n ;
   for(int i=0;i<n;i++){
       for(int j=0;j<=i;j++){
           
       cout<<"*";
       }
          cout<<"\n";
   }
 
    return 0;
}