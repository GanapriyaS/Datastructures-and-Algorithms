// REVISED BINARY SEARCH
// https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return binarySearch(nums, 0, n - 1, target);
    }
    
    int binarySearch(vector<int>& nums, int l, int r, int target)
    {   
        
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] == target)
                return m;

// inflection point to the right of me. left is strictly increasing              
            if(nums[m]>=nums[l]){
                if (nums[l] <= target && target < nums[m])
                    r = m - 1;
                else
                    l = m + 1;
            }  
// inflection point to the left of me. Right is strictly increasing
            else{
                if (nums[m] < target && target <= nums[r])
                    l = m + 1;
                else
                    r = m - 1;
            }
          
        }
        return -1;
    }
};

// Idea:
// Let's call the rotation the inflection point. (IP)
// One characteristic the inflection point holds is: arr[IP] > arr[IP + 1] and arr[IP] > arr[IP - 1]
// So if we had an array like: [7, 8, 9, 0, 1, 2, 3, 4] the inflection point, IP would be the number 9.

// One thing we can see is that values until the IP are ascending. And values from IP + 1 until end are also ascending (binary search, wink, wink).
// Also the values from [0, IP] are always bigger than [IP + 1, n].

// intuition:
// We can perform a Binary Search.
// If A[mid] is bigger than A[left] we know the inflection point will be to the right of us, meaning values from a[left]...a[mid] are ascending.

// So if target is between that range we just cut our search space to the left.
// Otherwise go right.

// The other condition is that A[mid] is not bigger than A[left] meaning a[mid]...a[right] is ascending.
// In the same manner we can check if target is in that range and cut the search space correspondingly.

// Time complexity: O(logn)
// Space complexity: O(1)
