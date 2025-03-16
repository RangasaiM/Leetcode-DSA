class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                int val=nums[i]+nums[j]+nums[k];
                if(val>0){
                    k--;
                }
                else if(val<0){
                    j++;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    k--;
                    j++;
                    while(j<k && nums[j-1]==nums[j]) j++;
                    while(j<k && nums[k+1]==nums[k]) k--;
                }
            }
        }
        return ans;
    }
};