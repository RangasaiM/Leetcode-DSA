class Solution {
public:
    void sortColors(vector<int>& nums) {
        int lo=0,mid=0,hi=nums.size()-1;
        for(mid;mid<=hi;){
            if(nums[mid]==0){
                swap(nums[lo],nums[mid]);
                lo++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[hi]);
                hi--;
            }
        }
    }
};