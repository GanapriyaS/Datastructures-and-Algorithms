// SOLUTION 1
// https://leetcode.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1; j<n;j++){
                if(nums[i]+nums[j]==target)
                    return {i,j};
            }
        }
        return {-1,-1};
    }
//Time Complexity:O(n^2)
};

// SOLUTION 2
class Solution {
public:
   vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
       
        for(int i=0;i<nums.size();i++)
            v.push_back({nums[i],i});
        sort(v.begin(),v.end());
       
        int i=0;
        int j=v.size()-1;
        int idx1=0;
        int idx2=0;
        while(i<j)
        {
            if(v[i].first+v[j].first==target)
            {
                idx1=v[i].second;
                idx2=v[j].second;
                break;
                
            }
            if(v[i].first+v[j].first<target)
                i++;
            if(v[i].first+v[j].first>target)
                j--;
    }
        return {idx1,idx2};
    }
//Time Complexity:O(nlogn)
//Time Complexity:O(n);
};

