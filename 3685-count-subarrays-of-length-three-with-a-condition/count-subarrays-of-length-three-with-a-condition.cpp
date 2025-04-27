class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int l=2,m=1,cnt=0;
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]+nums[l]==(nums[m]/2.0))
                cnt++;
            m++;
            l++;
        }
        return cnt;
    }
};