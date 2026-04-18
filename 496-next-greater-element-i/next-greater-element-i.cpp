class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();

        vector<int> ans;

        stack<int> st;

        unordered_map<int,int> mp;

        for(int i=n-1;i>=0;i--){
            int curr=nums2[i];

            while(!st.empty() && st.top()<=curr) st.pop();

            if(st.empty()) mp[curr]=-1;
            else
            mp[curr]=st.top();

            st.push(nums2[i]);
        }

        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }

        return ans;

    }
};