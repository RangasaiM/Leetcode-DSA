class Solution {
public:
    
    bool helper(string &s, string &p,int i,int j,vector<vector<int>>& dp){
        if(i==-1){
            if(j==-1) return true;
            if(p[j]=='*') return helper(s,p,i,j-1,dp);
            return false;
        }
        if(j==-1) return false;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        bool l=false;
        
        if(p[j]==s[i] || p[j]=='?'){
            l=helper(s,p,i-1,j-1,dp);
        }
        bool r=false;
        bool k=false;
        if(p[j]=='*'){
            r=helper(s,p,i-1,j,dp);
            k=helper(s,p,i,j-1,dp);
        }
        
        return dp[i][j]=r||l||k;
    }

    bool isMatch(string &s, string &p) {
        int m=s.length();
        int n=p.length();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return helper(s,p,m-1,n-1,dp);
    }
};