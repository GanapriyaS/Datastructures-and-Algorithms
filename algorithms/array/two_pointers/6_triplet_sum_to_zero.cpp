// Practise: https://leetcode.com/problems/3sum/

// Given an integer array nums- no duplicate triplets , return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]


// array
// we can sort
// find triplets
// loop + two sum

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include "2_two_sum.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> bruteForce(vector<int>& nums) {
        // time complexity: O(n^3)
        // space complexity: O(1)
        int n=nums.size();
        vector<vector<int>> result = {};
        for(int i=0;i<n-2;i++){
            for(int j=i+1; j<n-1;j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k] == 0){
                        vector<int> r= {nums[i],nums[j],nums[k]};
                        result.push_back(r);
                    }
                }     
            }
        }
        return result;
    }

    vector<vector<int>> twoPointer(vector<int>& nums) {
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
        vector<vector<int>> result;

        // array = -1 -1 0 1 2 4
        // i = 0 nums[i] = -1 sum = 1
        // {-1, 0, 1} -> 0
        // {-1, -1, 2} -> 0

        // i = 1 nums[i] = -1 sum = -1
        // {-1, 0, 1} -> 0  ====> Got duplicate triplets

        for(int i=0; i< n-2; i++){
            //this line is to eliminate duplicate triplets
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int left = i+1;
            int right = n-1;

            int sum = -nums[i];
            vector<vector<int>> temp = ob.twoSumTwoPointers(nums, sum, left, right);

            for(int j=0; j<temp.size(); j++){
                result.push_back({nums[i], temp[j][0], temp[j][1]});
            }
        }
        return result;
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
    
    sort(nums.begin(),nums.end()); //sorting the array important for two pointers

    Solution sol;
    vector<vector<int>> r = sol.bruteForce(nums);
    cout << "Brute Force: (with duplicate)\n";
    for(int i=0; i < r.size(); i++){
        for(int j=0; j < r[i].size(); j++){
            cout << r[i][j] << " ";
        }
        cout << endl;
    }

    r = sol.twoPointer(nums);
    cout << "Two Pointer: (without duplicate)\n";
    for(int i=0; i < r.size(); i++){
        for(int j=0; j < r[i].size(); j++){
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
   
    return 0;
}


// Enter the number of elements: 6
// Enter the elements: -1
// -1
// 0
// 1
// 2
// 4
// Enter the target: 0
// Brute Force: (with duplicate)
// -1 -1 2
// -1 0 1
// -1 0 1
// Two Pointer: (without duplicate)
// -1 -1 2
// -1 0 1