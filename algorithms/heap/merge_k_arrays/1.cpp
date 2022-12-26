// Practise : https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1/?page=4&category[]=Arrays&sortBy=submissions#

// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++
class data{
    public:
     int value;
     int index;
     int ele_index;
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    
    void heapify(data* arr, int n)
    {
        for(int i=n-1;i>=0;i--){
          
            int l=i*2+1;
            int r=i*2+2;
            int index=i;
            
            if(l<n && arr[i].value>arr[l].value) index=l;
            if(r<n && arr[index].value>arr[r].value) index=r;
        
            if(index!=i){
                data temp=arr[i];
                arr[i]=arr[index];
                arr[index]=temp;
            } 
        }
    }
    
    data deletion(data* arr,int n){
        data temp=arr[0];
        data lastElement = arr[n - 1];
        arr[n-1]=arr[0];
        arr[0] = lastElement;
        n = n - 1;
        heapify(arr, n);
        return temp;
    }
    
    void insertion(data* arr,int n,data temp){
    arr[n - 1] = temp;
    heapify(arr, n);
    }
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {   
        vector<int>answer;
    
        data temp[K];
        int j=K;
        for(int i=0;i<K;i++){
            temp[i].value=arr[i][0];
            temp[i].index=i;
            temp[i].ele_index=0;
        }
     
       
       heapify(temp,K);
       
       while(j>0){
       
        data t=deletion(temp,j);
        
        
        // for(int i=0;i<K;i++){
        //     cout<<temp[i].value<<"** ";
        // }
        
        // cout<<endl;
        answer.push_back(t.value);
     
       if(t.ele_index+1<K){
            data t1={arr[t.index][t.ele_index+1],t.index,t.ele_index+1};
            insertion(temp,j,t1);
        }
        else{
            j=j-1;
        }
       
        
        // for(int i=0;i<K;i++){
        //     cout<<temp[i].value<<" ";
        // }
        // cout<<endl;
       }
        
        return answer;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends
