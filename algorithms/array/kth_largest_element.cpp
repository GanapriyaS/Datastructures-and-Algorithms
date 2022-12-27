//     QUICK SORT ALGORITHM - REVERSE ORDER
// https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int partition(vector<int>& nums,int left,int right) {
        int pivot = nums[left], l=left+1, r = right;
        while(l<=r){
            if(nums[l]<pivot && nums[r]>pivot) swap(nums[l++],nums[r--]);
            if(nums[l]>=pivot) ++l;
            if(nums[r]<=pivot) --r;
        }
        swap(nums[left], nums[r]);
        return r;  
    }

    void swap(int &a, int &b){
        int tmp = a;
        a = b;
        b = tmp;
    }

    
    int findKthLargest(vector<int>& nums, int k) {
        int l=0,r=nums.size()-1,index=0;
        
        while(true){
            index=partition(nums,l,r);
            if(index==k-1)break;
            else if(index < k-1) l=index+1;
            else r=index-1;
        }
        return nums[index];
    }
};




