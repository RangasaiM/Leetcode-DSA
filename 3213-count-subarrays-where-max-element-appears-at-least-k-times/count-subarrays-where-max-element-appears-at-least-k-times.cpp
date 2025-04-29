class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
       long maxi=0,ans=0;
        for(long i:nums) maxi=max(maxi,i);
        
        int j=0,i=0;

        while(i<n){
            mp[nums[i]]++;
            while(mp[maxi]==k){
                ans+=n-i;
                mp[nums[j]]--;
                j++;
            }
            i++;
        }
        return ans;
    }
};