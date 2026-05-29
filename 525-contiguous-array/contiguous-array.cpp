class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        unordered_map<int,int> mp;
        int sum=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=(nums[i]==1?1:-1);

            if(mp.find(sum)!=mp.end()){
                maxi=max(i-mp[sum],maxi);
            }
            else{
                mp[sum]=i;
            }

        }
        return maxi;
    }
};