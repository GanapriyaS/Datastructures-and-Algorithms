// Practise : https://leetcode.com/problems/two-sum/solution/
// https://www.geeksforgeeks.org/cpp/map-vs-unordered_map-c/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSumBruteForce(vector<int>& nums, int target) {
        // time complexity: O(n^2)
        // space complexity: O(1)
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1; j<n;j++){
                if(nums[i]+nums[j]==target)
                    return {nums[i],nums[j]};
            }
        }
        return {-1,-1};
    }

    vector<int> twoSumHashTable(vector<int>& nums, int target) {
        // time complexity: O(n)
        // space complexity: O(n)

        // 2 elements -> 4 integers, 20 elements -> 40
        // 10^5 (lakh) -> 2x 10^5 elements -> 2 * 10^5 * 8byte -> 1600000 Bytes -> 1600 KB -> 1.6 MB
        // 10^9 -> 1.6 * 10^4 -> 16000 MB -> 16GB (RAM)
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            int complement=target-nums[i];
            if(mp.find(complement)!=mp.end())
                return {complement,nums[i]};
            mp[nums[i]]=nums[i];
        }
        return {-1,-1};
    }

    vector<int> twoSumTwoPointers(vector<int>& nums, int target) {
        // time complexity: O(n) (Sorting O(nlogn))
        // space complexity: O(1)
        int n=nums.size();
        int i=0,j=n-1;
        while(i<j)
        {
            if(nums[i]+nums[j]==target)
                return {nums[i],nums[j]};
            // sorted array so if sum is less than target then we need to increase the sum so we increment i, as left side element on increasing will increase the sum
            else if(nums[i]+nums[j]<target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return {-1,-1};
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
    int target;
    cout<<"Enter the target: ";
    cin>>target;
    sort(nums.begin(),nums.end()); //sorting the array important for two pointers

    Solution sol;
    vector<int> result = sol.twoSumBruteForce(nums, target);
    cout << "Brute Force: " << result[0] << " " << result[1] << endl;
    result = sol.twoSumHashTable(nums, target);
    cout << "Hash Table: " << result[0] << " " << result[1] << endl;
    result = sol.twoSumTwoPointers(nums, target);
    cout << "Two Pointers: " << result[0] << " " << result[1] << endl;

    return 0;
}


// Enter the number of elements: 4
// Enter the elements: 1
// 2
// 3
// 4
// Enter the target: 5
// Brute Force: 1 4
// Hash Table: 2 3
// Two Pointers: 1 4
