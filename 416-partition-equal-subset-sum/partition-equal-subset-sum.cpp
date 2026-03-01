class Solution {
public:

     bool helper(int ind,int k,vector<int>& arr,vector<vector<int>> &dp){
        if(k==0) return true;
        if(ind<0) return false;
        if(dp[ind][k]!=-1) return dp[ind][k];
        bool notTake=helper(ind-1,k,arr,dp);
        bool take=false;
        
        if(k-arr[ind]>=0)
            take=helper(ind-1,k-arr[ind],arr,dp);
            
        return dp[ind][k]=notTake||take;
    }

    bool canPartition(vector<int>& arr) {
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2!=0) return false;
        
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        
        return helper(n-1,sum/2,arr,dp);
    }

};