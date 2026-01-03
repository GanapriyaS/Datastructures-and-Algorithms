// Reference : https://www.geeksforgeeks.org/two-pointers-technique/
// Practise : https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1/?page=2&category[]=Arrays&sortBy=submissions#

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int a[],int n){
        int j=0,count=0;
        if(n==0 && n==1) return n;
        for(int i=0;i<n-1;i++){
            if(a[i]!=a[i+1]){
                a[j++]=a[i];
            }
        }
        a[j]=a[n-1];
        return j+1;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}  // } Driver Code Ends
