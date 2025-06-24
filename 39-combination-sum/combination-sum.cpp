class Solution {
public:

    vector<vector<int>> ans;

    void getCombinations(vector<int> a,int target,int i,vector<int> x){

        if(target<0){
            return;
        }

        if(i>=a.size()){
            if(target==0){
                ans.push_back(x);
            }
            return;
        }

        x.push_back(a[i]);
        getCombinations(a,target-a[i],i,x);
        x.pop_back();
        getCombinations(a,target,i+1,x);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        getCombinations(candidates,target,0,{});
        return ans;
    }
};