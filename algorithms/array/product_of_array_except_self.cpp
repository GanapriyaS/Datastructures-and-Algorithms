// SOLUTION 1
// https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int mul=1;
        vector<int> ans;
        
        for(int i=1;i<n;i++){
            mul*=nums[i];
        }
        ans.push_back(mul);
        for(int i=1;i<n;i++){
            if(nums[i]!=0){
            mul=(mul*nums[i-1])/nums[i];
            ans.push_back(mul);
            }
            else{
                int s=1;
                for(int j=0;j<n;j++){
                    if(i!=j) {
                     s=s*nums[j];
                    }
                }
                ans.push_back(s);
            }
        }
        return ans;
    }
};

// SOLUTION 2
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int mul=1;
        vector<int> ans;
        
              
        for(int i=0;i<n;i++){
            ans.push_back(mul);
            mul*=nums[i];
        }
        mul=1;
        
        for(int i=n-1;i>-1;i--){
            ans[i]=ans[i]*mul;
            mul*=nums[i];
        }
        return ans;
    }
};
