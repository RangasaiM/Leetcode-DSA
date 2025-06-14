class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> mp = {
            {'{', '}'},
            {'[', ']'},
            {'(', ')'}
        };
        stack<char> st;
        for(char ch:s){
            if(ch=='{' || ch=='[' || ch=='('){
                st.push(ch);
            }
            else{
                if(!st.empty() && mp[st.top()]==ch) st.pop();
                else return false;
            }
        }
        return st.empty();
    }
};