// https://www.enjoyalgorithms.com/blog/maximum-subarray-

class Solution {
public:
    int maxSubArray(vector<int>& arr) {
        int n=arr.size();
        int maxend=arr[0];
        int sum=arr[0];
        
        for(int i=1;i<n;i++){
            maxend=maxend+arr[i]>arr[i]?maxend+arr[i]:arr[i];
            sum=maxend>sum?maxend:sum;
        }
        return sum;
    }
};
