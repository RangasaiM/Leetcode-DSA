class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=1;
        int curr=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(curr!=nums[i]){
                if(cnt>1) cnt--;
                else{
                    curr=nums[i];
                }
            }
            else cnt++;
        }
        return curr;
    }
};