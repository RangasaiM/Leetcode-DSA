class Solution {
public:

    void helper(vector<int>& nums,vector<int> temp,vector<vector<int>> &ans,vector<bool>& taken){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(!taken[i]){
                taken[i]=true;
                temp.push_back(nums[i]);
                helper(nums,temp,ans,taken);
                taken[i]=false;
                temp.pop_back();
            }
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> taken(nums.size(),false);
        vector<vector<int>> ans;
        helper(nums,{},ans,taken);

        return ans;

    }
};