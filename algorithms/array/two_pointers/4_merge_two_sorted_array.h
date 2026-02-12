
// Practise :

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class SolutionMerge{
public:
    int* merge_sorted_array(int* a,int n, int* b, int m){
        // time complexity: O(m+n)
        // space complexity: O(1)
        int j=0;
        int k=0;
        // int* c[n+m]; local array cannot return so use dynamic array
        int* c = new int[n+m];
        for(int i=0;i<n+m;i++){
            if(j < n && k < m){
              if(a[j] <= b[k]){
                c[i] = a[j];
                j++;
              }
              else{
                c[i] = b[k];
                k++;
              }
            }
            else if(j < n){
                c[i] = a[j];
                j++;
            }
            else if(k < m){
                c[i] = b[k];
                k++;
            }
        }
        return c;
    }

    int* while_merge_sorted_array(int* a,int n, int* b, int m){
        // time complexity: O(m+n)
        // space complexity: O(1)

        int* c = new int[n + m];   // allocate dynamically

        int i = 0, j = 0, k = 0;

        while(j < n && k < m){
            if(a[j] <= b[k]){
                c[i++] = a[j++];
            }
            else{
                c[i++] = b[k++];
            }
        }

        while(j < n){
            c[i++] = a[j++];
        }

        while(k < m){
            c[i++] = b[k++];
        }

        return c;
    }
};

// // { Driver Code Starts.
// int main()
// {
//     int T;
//     cout<<"Enter the number of testcases: ";
//     cin>>T;
//     while(T--)
//     {   
//         cout<<"Enter the number of elements in first array: ";
//         int N;
//         cin>>N;
//         int a[N];
//         for(int i=0;i<N;i++)
//         {
//             cin>>a[i];
//         }

//         cout<<"Enter the number of elements in second array: ";
//         int M;
//         cin>>M;
//         int b[M];
//         for(int i=0;i<M;i++)
//         {
//             cin>>b[i];
//         }
//     SolutionMerge ob;
//     int* c = ob.merge_sorted_array(a,N,b,M);

//     for(int i=0;i<M+N;i++)
//         cout<<c[i]<<" ";
//     cout<<"\n";


//     c = ob.while_merge_sorted_array(a,N,b,M);

//     for(int i=0;i<M+N;i++)
//         cout<<c[i]<<" ";
//     cout<<endl;
//     }
// }  // } Driver Code Ends
