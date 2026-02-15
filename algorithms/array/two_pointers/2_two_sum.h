// Practise : https://leetcode.com/problems/two-sum/solution/
// https://www.geeksforgeeks.org/cpp/map-vs-unordered_map-c/

#include<iostream>
#include<vector>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

class SolutionTwoSum {
public:
    vector<vector<int>> twoSumTwoPointers(vector<int>& nums, int target, int left, int right) {
        // time complexity: O(n) (Sorting O(nlogn))
        // space complexity: O(1)
        int n=nums.size();
        vector<vector<int>> result;
        while(left<right)
        {   
            if(nums[left]+nums[right]==target){
                // 1 1 1 2 2 2 2 2 3 3 3
                result.push_back({nums[left], nums[right]});
                left++;
                right--;

                // sorted array so if sum is less than target then we need to increase the sum so we increment i, as left side element on increasing will increase the sum
                // while loop to eliminate the duplicate pairs irrespective of indexaa
                while(left<n && nums[left] == nums[left-1]){
                    left++;
                }
                while(right>=0 && nums[right] == nums[right+1]){
                    right--;
                }
                
            }else if(nums[left]+nums[right]<target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return result;
    }

    int twoSumTwoPointersCloset(vector<int>& nums, int left, int right,int target ) {
        // time complexity: O(n) (Sorting O(nlogn))
        // space complexity: O(1)
        int n=nums.size();
        int closest_sum= nums[left] + nums[right];
        while(left<right)
        {   
            int sum = nums[left] + nums[right];
            if(sum==target){
                return sum;
            }

            if (abs(target - sum) < abs(target - closest_sum)) {
               closest_sum = sum;
            }
            if(sum<target)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
        return closest_sum;
    }
};
