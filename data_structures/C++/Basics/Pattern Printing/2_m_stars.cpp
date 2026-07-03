// B. M-Stars
// time limit per test1 second
// memory limit per test256 megabytes
// You are given two integers n and m. Your task is to print a rectangle pattern consisting of n rows and m columns, where each cell contains a star '*'.

// Input
// The only line contains two integers n and m (1≤n,m≤200).

// Output
// Print the pattern.

// Examples
// Input
// 5 6
// Output
// ******
// ******
// ******
// ******
// ******
// Input
// 3 5
// Output
// *****
// *****
// *****


using namespace std;
int main() {
   int n,m;
   cin >> n >>m;
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
       cout<<"*";
       }
          cout<<"\n";
   }
 
    return 0;
}