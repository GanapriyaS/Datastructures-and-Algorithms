// Practise: https://leetcode.com/problems/squares-of-a-sorted-array/description/

// array
// sorted
// merge 2 sorted array

#include<iostream>
#include<vector>
#include<algorithm>
#include "4_merge_two_sorted_array.h"
using namespace std;

class Solution {
public:
    void swap(int *a,int *b)
    {
        int t=*a;
        *a=*b;
        *b=t;
    }
    int partition(vector<int>& a,int low,int high)
    {
        int pivot=a[low];
        int i=low;
        int j=high;
        while(i<j)
        {
            while(a[i]<=pivot)i++;
            while(a[j]>pivot)j--;
            if(i<j)swap(&a[i],&a[j]);
        }
        swap(&a[low],&a[j]);
        return j;
    }
    void quickSort(vector<int>& arr,int low,int high)
    {
        if(low<high)
        {
            int pos=partition(arr,low,high);
            quickSort(arr,low,pos-1);
            quickSort(arr,pos+1,high);
        }
    }



    vector<int> sortedSquares(vector<int>& nums) {
        // time complexity: O(n) (Sorting O(nlogn))
        // space complexity: O(1)
        for(int i=0; i<nums.size();i++){
            nums[i] = nums[i] * nums[i];
        }
        quickSort(nums,0, nums.size()-1);
        return nums;
        
    }

    vector<int> twoPointersSortedSquares(vector<int>& nums) {
        // time complexity: O(n)
        // space complexity: O(1)

        // Same as merge 2 sorted array
        // -4 -2 -1  asc , 16 4 1 desc
        // 1 2 4 asc, 1 4 8 desc

        vector<int> neg;
        vector<int> pos;
        for(int i=0; i<nums.size();i++){
            if(nums[i] >=0)
                pos.push_back(nums[i] * nums[i]);
            else
                neg.push_back(nums[i] * nums[i]);
        }

        int n = neg.size();
        int m = pos.size();

        if(n == 0){
            // whole array is positive
            return pos;
        }

        if(m == 0){
            // whole array is positive
            reverse(neg.begin(), neg.end());
            return neg;
        }

        reverse(neg.begin(), neg.end());

        int* a = neg.data();   // pointer to vector data
        int* b = pos.data();

        SolutionMerge ob;

        int* merged = ob.merge_sorted_array(a, n, b, m);
        vector<int> result(merged, merged + n + m);
        delete[] merged;
        return result;
        
    }
};


// { Driver Code Starts.
int main()
{
    int T;
    cout<<"Enter the number of testcases: ";
    cin>>T;
    while(T--)
    {
        int N;
        cout<<"Enter the number of elements: ";
        cin>>N;
        vector<int> a(N);
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    ob.sortedSquares(a);

    for(int i=0;i<N;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    int M;
    cout<<"Enter the number of elements: ";
    cin>>M;
    vector<int> b(M);
    for(int i=0;i<M;i++)
    {
        cin>>b[i];
    }

    vector<int> result = ob.twoPointersSortedSquares(b);

    for(int i=0;i<M;i++)
        cout<<result[i]<<" ";
    cout<<endl;
    }
}  // } Driver Code Ends

/** 
vector<int> a = {1,2};
vector<int> b = {10,20};

vector<int>* p = &a; // POINTER
p = &b;   // allowed

vector<int>& v // REFERENCE - cannot make refer to another vector later
**/

/** REFERENCE
It is an alias to the original vector
Cannot be NULL
No need to use * or ->
Safe & clean
Must be initialized when declared

void func(vector<int>& v)
{
    v[0] = 100;
}
vector<int> a = {1,2,3};
func(a);

cout << a[0];   // 100
*/



/** POINTER
Stores memory address
Can be NULL
Must use * or ->
More error-prone
Needs dereferencing

void func(vector<int>* v)
{
    (*v)[0] = 100; // v->at(0) = 100;
}

vector<int> a = {1,2,3};
func(&a);

cout << a[0];   // 100
*/



/**
void func(vector<int> v)
{
    v[0] = 100;
}

vector<int> a = {1,2,3};
func(a);
cout << a[0];   // Output: 1
*/