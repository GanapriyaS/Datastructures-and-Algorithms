// https://leetcode.com/problems/maximum-product-subarray/

class Solution {
public:
    int maxProduct(vector<int>& arr) {       
        int n=arr.size();
        int min=arr[0];
        int max=arr[0];
        int mul=arr[0];
        
        for(int i=1;i<n;i++){
// If the -ve neg found alter min to max , viceversa i.e - * - = +  
            if(arr[i]<0){
	          int tmp=max;
	          max=min;
	          min=tmp;
	    }
            
            min=min*arr[i]<arr[i]?min*arr[i]:arr[i];
	        max=max*arr[i]>arr[i]?max*arr[i]:arr[i];
            mul=max>mul?max:mul;
        }
        return mul;
    }
};