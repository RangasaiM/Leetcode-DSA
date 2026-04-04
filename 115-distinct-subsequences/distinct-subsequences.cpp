class Solution {
public:
    int helper(string &s1, string &s2,int i,int j,vector<vector<int>>& dp){
        if(j==-1) return 1;
        if(i==-1) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int pick=0;
        if(s1[i]==s2[j])
            pick= helper(s1,s2,i-1,j-1,dp);
        
        int notpick=helper(s1,s2,i-1,j,dp);
        
        return dp[i][j]=pick+notpick;
    }

    int numDistinct(string &s1, string &s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(s1,s2,n-1,m-1,dp);
    }
};