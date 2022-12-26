// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
		deque<int> d;
		vector<int>ans;
		for (int i = 0; i < n; i++) {
			while ((!d.empty()) && nums[i]>=nums[d.back()])  
				d.pop_back();
			d.push_back(i);
            if(d.front()==i-k){
                d.pop_front();
            }
            if(i>=k-1){
                ans.push_back(nums[d.front()]);
            }
		}
		return ans;
    }
};
