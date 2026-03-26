class Solution {
public:

    int helper(vector<int>& arr, int amount,int i,vector<vector<long>>& dp){
        if(i<0 || amount<0) return INT_MAX;
        
        if(amount==0) return 0;
        
        if(dp[i][amount]!=-1) return dp[i][amount];

        
        int r=helper(arr,amount-arr[i],i,dp);

        if (r != INT_MAX) r += 1;

        int k=helper(arr,amount,i-1,dp);
        
        return dp[i][amount]=min(r,k);
        
    }
    
    int coinChange(vector<int>& arr, int amount) {
        int n=arr.size();
        vector<vector<long>> dp(n,vector<long>(amount+1,-1));
        int ans=helper(arr,amount,n-1,dp);
        if(ans==INT_MAX) return -1;

        return ans;
        
    }

};