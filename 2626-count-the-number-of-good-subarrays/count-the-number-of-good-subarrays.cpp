class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long n=nums.size();
        unordered_map<long long ,long long> mp;
        long long good=0;
        long long equals=0;
        long long left=0,right=0;
        while(left<n){
            while(right<n && equals<k){
                mp[nums[right]]++;
                if(mp[nums[right]]>1) equals+=mp[nums[right]]-1;
                right++;
            }
            if(equals>=k) good+=n-right+1;
            
            mp[nums[left]]--;
            if(mp[nums[left]]>0)
                equals-=mp[nums[left]];
            left++;
        }
        return good;
    }
};