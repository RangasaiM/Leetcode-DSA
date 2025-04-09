class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]<k) return -1;
        }
        set<int> st;
        st.insert(k);
        for(int i:nums){
            st.insert(i);
        } 
        int cnt=st.size();
        int l=st.size();
        for(int i:st){
            cout<<i<< " ";
            if(i==k){
                break;
            }
            cnt--;
        }
        if(cnt==1 && l>1)
            return -1;
        return cnt-1;
    }
};