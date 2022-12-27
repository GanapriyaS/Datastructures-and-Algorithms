// https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int l = 0;
        int r = n - 1;
        int max_area = 0;
        
        while (l < r){
            if (height[l] >= height[r]){
                max_area = max(max_area,height[r]*(r-l));
                r -= 1;
            }
            else{
                max_area = max(max_area,height[l]*(r-l));
                l += 1;
            }
        }
        
        return max_area;
    }
};

