// SOLUTION 1 - Time limit exceeded
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max=0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1; j<n;j++){
                int profit=prices[j]-prices[i];
                if(profit> max)
                    max=profit;
            }
        }
        return max;
    }
};

// SOLUTION 2
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int max=0,min=INT_MAX;
        for(int i=0;i<n;i++){
            if(prices[i]<min)
                min=prices[i];
          
            if(prices[i]-min> max)
                max=prices[i]-min;
        }
        return max;
    }
};