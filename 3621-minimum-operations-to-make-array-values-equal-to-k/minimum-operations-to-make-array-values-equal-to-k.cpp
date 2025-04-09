class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<k) return -1;
        }
        unordered_set<int> st;
        for(int i:nums){
            if(i>k)
                st.insert(i);
        } 
        return st.size();
    }
};