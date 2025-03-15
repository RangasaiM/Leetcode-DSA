class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
            int k=target-nums[i];
            if(mp.find(k)!=mp.end() && i!=mp[k]){
                index.push_back(i);
                index.push_back(mp[k]);
                return index;
            }
        }
        return index;
    }
};