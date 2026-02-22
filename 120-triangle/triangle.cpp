class Solution {
public:


    int helper(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>> &dp){
        if(i==n-1) return triangle[i][j];
        
        if(dp[i][j]!=INT_MAX) return dp[i][j];
        
        int l=helper(i+1,j,triangle,n,dp);
        int r=helper(i+1,j+1,triangle,n,dp);
        
        return dp[i][j]=min(l,r)+triangle[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle){
        int n=triangle.size();
        vector<vector<int>> dp(n);
        for(int i = 0; i < n; i++)
            dp[i] = vector<int>(i+1, INT_MAX);
        return helper(0,0,triangle,n,dp);
    }
};