class Solution {
public:

    void helper(int k,int n,vector<int> temp,vector<vector<int>>& ans,int i,int sum){
        if(sum==n && temp.size()==k){
            ans.push_back(temp);
            return;
        }
        if(i==10 || sum>n) return; 

        for(int ind=i;ind<=9;ind++){
            temp.push_back(ind);
            helper(k,n,temp,ans,ind+1,sum+ind);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        helper(k,n,{},ans,1,0);
        return ans;
    }
};