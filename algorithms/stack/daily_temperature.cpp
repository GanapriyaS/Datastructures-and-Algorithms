// https://leetcode.com/problems/daily-temperatures/

class Solution {
public:
    int top=-1;
    int n;
    void push(int* stk,int s){
        if(top!=n-1){
          stk[++top]=s;
        }
    }
    int pop(int* stk){
        return top==-1?-1:stk[top--];
    }
    
   
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        n=temperatures.size();
        int stk[n];
        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(0);
        }
        for(int i=n-1;i>=0;i--){
            if(top==-1) ans[i]=0;
            else{
                while(!(top==-1) && temperatures[i]>=temperatures[stk[top]]){
                    pop(stk);    
                }
                ans[i]=top==-1?0:(stk[top]-i);
            }
            push(stk,i);
        }
        
        return ans;
    }
};
