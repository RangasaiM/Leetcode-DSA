class Solution {
public:
    int findMin(vector<int>& nums) {
        int lo=0,hi=nums.size()-1;
        int ans=INT_MAX;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(ans>nums[mid]) ans=nums[mid];
            if(nums[lo]>nums[mid] && nums[mid]<nums[hi]){
                hi=mid-1;
            }
            else if(nums[lo]<nums[mid] && nums[mid]<nums[hi]) hi=mid-1;
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};