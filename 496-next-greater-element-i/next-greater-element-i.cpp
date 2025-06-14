class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ngeMap;
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            int curr = nums2[i];
            while (!st.empty() && st.top() <= curr) {
                st.pop();
            }
            ngeMap[curr] = st.empty() ? -1 : st.top();
            st.push(curr);
        }

        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(ngeMap[num]);
        }

        return ans;
    }
};