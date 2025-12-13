class Solution {
public:

    void helper(int n,string s,vector<string>& ans){
        if(s.length()==n){
            ans.push_back(s);
            return;
        }
        if(s=="" || s.back()!='0'){
            helper(n,s+"0",ans);
        }
        helper(n,s+'1',ans);
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        helper(n,"",ans);
        return ans;
    }
};