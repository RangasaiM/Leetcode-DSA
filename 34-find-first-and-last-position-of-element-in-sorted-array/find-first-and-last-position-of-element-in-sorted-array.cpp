class Solution {
public:

    int floor(vector<int>& nums,int k){
        int lo=0;
        int hi=nums.size()-1;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]<=k){
                ans=mid;
                lo=mid+1;
            }
            else{
                hi=mid-1;
            }
        }
        if(ans!=-1 && nums[ans]==k) return ans;
        return -1;
    }

    int ceil(vector<int>& nums,int k){
        int lo=0;
        int hi=nums.size()-1;
        int ans=-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]>=k){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        if(ans!=-1 && nums[ans]==k) return ans;
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int x=ceil(nums,target);
        int y=floor(nums,target);
        return {x,y};
    }
};