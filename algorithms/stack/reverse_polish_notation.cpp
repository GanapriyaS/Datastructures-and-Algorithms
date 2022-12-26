// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    
     int top;
    int n;
    void push(int* stk,int s){
        if(top!=n-1){
          stk[++top]=s;
        }
    }
    int pop(int* stk){
        return top==-1?-1:stk[top--];
    }    
    
    int evalRPN(vector<string>& tokens) {
        top=-1;
        n=tokens.size();
        int res=0;
        int stk[n];
        for(int i=0;i<n;i++){
            if(tokens[i]!="*" && tokens[i]!="-" && tokens[i]!="+" && tokens[i]!="/" ){
                int n=stoi(tokens[i]);
                push(stk,n);      
            }
            else{
                int b=pop(stk);
                int a=pop(stk);
                
                if(tokens[i]=="+")res=a+b;
                else if(tokens[i]=="-")res=a-b;
                else if(tokens[i]=="/")res=a/b;
                else res=a*b;
                push(stk,res);
                }     
            }
        return pop(stk);
    }
        
};
