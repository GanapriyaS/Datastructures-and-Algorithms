// Kadane's algorithm 
// https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n=arr.size();
        int maxend=arr[0];
        int sum=arr[0];
        
        for(int i=1;i<n;i++){
            if(arr[i]<arr[i]+maxend)
                maxend=arr[i]+maxend;
            else
                maxend=arr[i];
            
            if(maxend>sum)
                sum=maxend;
        }
        return sum;
    }
};
