class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i=-1;
        int n=nums.size()-1;
        for(int j=n;j>=1;j--){
            if(nums[j]>nums[j-1]){
                i=j-1;
                break;
            }
        }
        if(i!=-1){
            for(int j=n;j>=0;j--){
                if(nums[i]<nums[j]){
                    swap(nums[i],nums[j]);
                    break;
                }
            }
            reverse(nums.begin()+(i+1),nums.end());
        }
        else{
            sort(nums.begin(),nums.end());
        }
    }
};