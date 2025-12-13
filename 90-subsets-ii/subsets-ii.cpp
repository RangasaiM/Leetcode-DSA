class Solution {
public:

    void helper(vector<int>& nums,vector<vector<int>>& ans,vector<int> temp,string s,int i){
        if(i==nums.size()){
            ans.push_back(temp);
            // st.insert(s);
            return;
        }
        // if(i==nums.size()) return;
        temp.push_back(nums[i]);
        helper(nums,ans,temp,s+to_string(nums[i]),i+1);
        temp.pop_back();
        int j=i+1;
        while(j<nums.size() && nums[i]==nums[j]) j++;
        helper(nums,ans,temp,s,j);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // unordered_set<string> st;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        helper(nums,ans,{},"",0);
        return ans;
    }
};