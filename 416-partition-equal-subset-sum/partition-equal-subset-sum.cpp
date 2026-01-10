class Solution {
public:

    bool helper(vector<int>& nums,int total,int sum,int i,int n,vector<vector<int>>& dp){
        if(total==sum) return true;
        if(total<sum) return false;
        if(i==n) return false;

        if(dp[i][total]!=-1){
            return dp[i][total]; 
        }
        
        

        bool k=helper(nums,total-nums[i],sum,i+1,n,dp); 
        bool m=helper(nums,total,sum,i+1,n,dp); 
        
        return dp[i][total]=k||m;
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();

        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum%2) return false;

        int total=sum;

        sum=sum/2;
        vector<vector<int>> dp(nums.size(), vector<int>(total + 1, -1));
        return helper(nums,total,sum,0,n,dp);
    }
};