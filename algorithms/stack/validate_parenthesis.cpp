// https://leetcode.com/problems/valid-parentheses/

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
    
    bool isValid(string s) {
        n=s.length();
        int stk[n];
        for(int i=0;i<n;i++){
            if(s[i]==40) push(stk,40);
            else if(s[i]==91) push(stk,91);
            else if(s[i]==123)push(stk,123);
            else{
                int ck=pop(stk);
                if((s[i]==41 && ck==40) || (s[i]==93 && ck==91) ||(s[i]==125 && ck==123))
                    continue;
                return false;
            }
        }
        return top==-1?true:false;
        
    }
};
