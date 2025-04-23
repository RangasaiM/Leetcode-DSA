class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        long lo=0,hi=nums.size()-1;
        if(n==1)
            return nums[0];
        else if(nums[0]!=nums[1]) return nums[0];
        else if(nums[n-1]!=nums[n-2]) return nums[n-1];
        while(lo<=hi){
            long mid=(lo+hi)/2;
            if((nums[mid+1]!=nums[mid] && nums[mid-1]!=nums[mid])){
                return nums[mid];
            }
            else if(mid+1<n && mid-1>=0 && ((nums[mid-1]==nums[mid] && mid%2==0) || (nums[mid+1]==nums[mid] && mid%2!=0))){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }

        }
        return nums[0];
    }
};