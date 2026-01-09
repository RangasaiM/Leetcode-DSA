class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        int l=0;
        int r=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                l++;
                r++;
            }
            else if(s[i]==')'){
                l--;
                r--;
            }
            else{
                l--;
                r++;
            }
            if(l==-1) l=0;
            if(r==-1) return false;
        }
        if(l==0)
            return true;
        return false;
    }
};