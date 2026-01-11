class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int ans=0;
        for (int x : st) {
            if (st.find(x - 1) == st.end()) {
                int cnt = 1;
                int curr = x + 1;
                while (st.find(curr) != st.end()) {
                    cnt++;
                    curr++;
                }
                ans = max(ans, cnt);
            }
        }
        return ans;
    }
};