// Practise: https://leetcode.com/problems/3sum-closest/

// Given an integer array nums of length n and an integer target, find three integers at distinct indices in nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include "2_two_sum.h"
using namespace std;

class Solution {
public:

    int twoPointer(vector<int>& nums, int target) {
        // sort -> nlogn
        // i => 0 to n-2 (n-2)
        // ---for each (n-2) => left(half array), right(half array) (n)
        // O(n^2)

        // time complexity: O(n^2)

        // {a[0], a[1], a[2]}
        // a[i] + x + y = 0                                  
        // x + y = - a[i] find pair with given sum
        SolutionTwoSum ob;
        int n=nums.size();
        int closest_sum = nums[0] + nums[1] + nums[2];


        for(int i=0; i< n-2; i++){
            //this line is to eliminate duplicate triplets
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = n-1;

            int sum = -nums[i];
            int temp = ob.twoSumTwoPointersCloset(nums, left, right, sum);

            if(abs(target -(temp + nums[i])) <abs(target - closest_sum)){
                closest_sum = temp + nums[i];
            }
        }
        return closest_sum;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int closestSum = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if(abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                }

                if(sum < target) {
                    left++;
                }
                else if(sum > target) {
                    right--;
                }
                else {
                    return sum;  // exact match
                }
            }
        }
        return closestSum;
    }
};

int main() //Sorted Array or number/element asked (then sort urself)
{
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int> nums(n);
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++)
    {
        cin>>nums[i];
    }
    cout<<"Enter target:";
    int target;
    cin>>target;
    
    sort(nums.begin(),nums.end()); //sorting the array important for two pointers

    Solution sol;
    int r = sol.twoPointer(nums, target);
    
    cout << "Two pointer closet sum : " << r << endl;

    r = sol.threeSumClosest(nums, target);
    
    cout << "Two pointer closet sum : " << r;
    return 0;
}


// Enter the number of elements: 4
// Enter the elements: -1
// 2
// 1
// -4
// Enter target:1
// Two pointer closet sum : 2
// Two pointer closet sum : 2