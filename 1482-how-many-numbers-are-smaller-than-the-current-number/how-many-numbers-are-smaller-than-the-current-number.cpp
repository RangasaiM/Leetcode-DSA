class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp=nums;
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(auto i:temp){
            ans.push_back(lower_bound(nums.begin(),nums.end(),i)-nums.begin());
        }
        return ans;
    }
};