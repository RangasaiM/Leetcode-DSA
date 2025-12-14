class Solution {
public:

    void helper(string digits,vector<string>& ans,int ind,vector<string>& nums,string str){
        if(ind==digits.size()){
            ans.push_back(str);
            return;
        }
        int j=digits[ind]-'0';
        for(int i=0;i<nums[j].size();i++){
            helper(digits,ans,ind+1,nums,str+nums[j][i]);
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> nums = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        helper(digits,ans,0,nums,"");
        return ans;
    }
};