class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int total=(n*(n+1))/2;
        int asum=0;
        for(auto i:nums){
            asum+=i;
        }
        return total-asum;
    }
};