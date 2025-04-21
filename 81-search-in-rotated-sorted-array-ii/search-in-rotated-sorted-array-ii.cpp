class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[lo] && nums[hi]==nums[lo]){
                lo++;
                hi--;
                continue;
            }
            if(nums[mid]>=nums[lo]){
                if(nums[lo]<=target && nums[mid]>target){
                    hi=mid-1;
                }
                else lo=mid+1;
            }
            else{
                if(nums[hi]>=target && nums[mid]<target){
                    lo=mid+1;
                }
                else hi=mid-1;
            }
        }
        return false;
    }
};