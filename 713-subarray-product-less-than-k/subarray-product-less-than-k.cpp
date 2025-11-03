class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        if(k<=1) return 0;
        int cnt=0;
        int l=0;
        int n=arr.size();
        long long currPro=1;
        for(int i=0;i<n;i++){
            currPro*=arr[i];
            while(currPro>=k){
                currPro/=arr[l];
                l++;
            }
            cnt+=(i-l+1);
        }
        return cnt;
    }
};