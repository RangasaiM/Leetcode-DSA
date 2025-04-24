class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_map<int,int> mp;
        unordered_set<int> st;
        int n=nums.size();
        for(int i:nums){
            st.insert(i);
        }
        int unq=st.size();
        int i=0,j=0,res=0;
        while(i<n){
            mp[nums[i]]++;
            while(mp.size()==unq){
                res+=n-i;
                mp[nums[j]]--;
                if(mp[nums[j]]==0) mp.erase(nums[j]);
                j++;
            }
            i++;
        }

        return res;
    }
};