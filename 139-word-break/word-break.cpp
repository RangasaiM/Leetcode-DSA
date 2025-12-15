class Solution {
public:

    bool helper(string s,unordered_set<string>& myset,int ind,vector<int>& dp){
        if(ind==s.size()) return true;

        if(dp[ind]!=-1) return dp[ind];

        for(int i=ind;i<s.size();i++){
            string temp=s.substr(ind,i-ind+1);
            if(myset.find(temp)!=myset.end()){
                if(helper(s,myset,i+1,dp)){
                    return dp[ind]=1;
                }
            }
        }
        return dp[ind]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> myset;
        vector<int> dp(s.size(),-1);
        for(auto i:wordDict){
            myset.insert(i);
        }
        return helper(s,myset,0,dp);
    }
};