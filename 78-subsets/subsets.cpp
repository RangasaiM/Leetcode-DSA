class Solution {
public:

    void getAll(vector<int>& nums,int i,vector<vector<int>>& ans,vector<int> temp){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        getAll(nums,i+1,ans,temp);
        temp.pop_back();
        getAll(nums,i+1,ans,temp);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        getAll(nums,0,ans,{});
        return ans;
    }
};