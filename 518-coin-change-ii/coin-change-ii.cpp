class Solution {
public:


    int helper(vector<int>& arr, int amount,int i,vector<vector<int>>& dp){
        if(i<0 || amount<0) return 0;
        
        if(amount==0) return 1;
        
        if(dp[i][amount]!=-1) return dp[i][amount];
        
        int r=helper(arr,amount-arr[i],i,dp);
        int k=helper(arr,amount,i-1,dp);
        
        return dp[i][amount]=r+k;
        
    }
    
    int change(int amount,vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return helper(arr,amount,n-1,dp);
    }
};