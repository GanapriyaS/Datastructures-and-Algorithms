// Practise: https://www.geeksforgeeks.org/problems/count-triplets-with-sum-smaller-than-x5549/1

// Given an array arr[] of distinct integers of size n and a value sum, the task is to find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.

// Input: n = 4, sum = 2, arr[] = {-2, 0, 1, 3}
// Output:  2
// Explanation: Below are triplets with sum less than 2 (-2, 0, 1) and (-2, 0, 3). 


// a[i] + a[j] + a[k] < sum (no duplicates)
// 1 2 3 4 5 6 7 8 9 target=15
// 1 2 9 => 12
// 1 2 8 => 11
// .....
// 1 2 3 => 6
// right to left all will small after the point


#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include "2_two_sum.h"
using namespace std;

class Solution {
public:

    int twoPointer(vector<int>& nums, int target) {
        // time complexity: O(n^2)
        // space complexity: O(1)

        int n = nums.size();

        int ans = 0;

        for(int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < target) {
                    // All pairs (left, left+1 ... right) are valid
                    ans = ans + (right - left);
                    left++;
                }
                else {
                    // should not do left++ because
                    // -1 0 1 2 3 target is 3
                    // { -1, 1, 3 } = target if left++ then we will miss 
                    // { -1, 1, 2} which is valid triplet witj less sum
                    right--;
                }
            }
        }
        return ans;
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
    
    cout << "Two pointer triplets smaller sum : " << r;
    return 0;
}


// Enter the number of elements: 
// 6
// Enter the elements: -4
// -2
// 0
// 2
// 3
// 5
// Enter target:4
// Two pointer triplets smaller sum : 13