// Practise: https://leetcode.com/problems/sort-colors/description/


// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// - array, rearrange (inplace), sorted => two pointer

// Practise : https://leetcode.com/problems/two-sum/solution/
// https://www.geeksforgeeks.org/cpp/map-vs-unordered_map-c/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> bruteForce(vector<int>& nums) {
        // time complexity: O(n)
        // space complexity: O(n)

        vector<int> a = {};
        vector<int> b = {};
        vector<int> c = {};
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == 0) a.push_back(0);
            if(nums[i] == 1) b.push_back(1);
            if(nums[i] == 2) c.push_back(2);
        }
        vector<int> temp(a.size() + b.size());
        merge(a.begin(), a.end(),
            b.begin(), b.end(),
            temp.begin());

        vector<int> result(temp.size() + c.size());
        merge(temp.begin(), temp.end(),
            c.begin(), c.end(),
            result.begin());
        return result;
    }

    vector<int> bruteForce2(vector<int>& nums) {
        // time complexity: O(n)
        // space complexity: O(1)

        int zero = 0;
        int one = 0;
        int two = 0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i] == 0) zero+=1;
            if(nums[i] == 1) one+=1;
            if(nums[i] == 2) two+=1;
        }
        vector<int> temp;
        for(int i=0;i<zero; i++){
            temp.push_back(0);
        }
        for(int i=0;i<one; i++){
            temp.push_back(1);
        }
        for(int i=0;i<two; i++){
            temp.push_back(2);
        }
        return temp;
    }

 
    vector<int> twoPointers(vector<int>& nums) {
        // time complexity: O(n) (Sorting O(nlogn))
        // space complexity: O(1)
        // single pass approach
        int n=nums.size();
        int low=0,high=n-1, mid=0;

        //start .......00000 low ....array.... mid 11111....high
        // zero [start, low-1] 
        // two [high+1,end] 
        // one => [low, mid-1] (need to sort this )
        while(mid<high)
        {
            if(nums[mid] == 0){
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                low++;
                mid++;
            }
                
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
               int temp = nums[high];
                nums[high] = nums[mid];
                nums[high] = temp;
                high--;
                //mid++ should not be added as it may be greater or lower or equal to 1 need to check after swap
            }
        }
        return nums;
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
    vector<int> result = sol.bruteForce(nums);
    cout << "Brute Force: "<< endl;
    for(int i=0;i<n;i++){
        cout << result[i] << " ";
    }
    cout << endl;

    result = sol.bruteForce2(nums);
    cout << "Brute Force (2): " << endl;
     for(int i=0;i<n;i++){
        cout << result[i] << " ";
    }
    cout << endl;

    result = sol.twoPointers(nums);
    cout << "Two Pointers: " << endl;
     for(int i=0;i<n;i++){
        cout << result[i] << " ";
    }
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
