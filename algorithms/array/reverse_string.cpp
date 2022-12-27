// https://leetcode.com/problems/reverse-string/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int len=s.size();
        for(int i=0;i<len/2;i++){
            char tmp=s[i];
            s[i]=s[len-i-1];
            s[len-i-1]=tmp;
        }
    }
};


class Solution {
public:
    void reverseString(vector<char>& s) {
        int i=0;
        int j=s.size()-1;
        while(i<j){
            int tmp=s[i];
            s[i++]=s[j];
            s[j--]=tmp;
        }
    }
};