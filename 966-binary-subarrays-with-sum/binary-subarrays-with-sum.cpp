class Solution {
public:
        int atMostK(vector<int>& arr, int k){
        if (k < 0) return 0;
        int n=arr.size();
        int j=0;
        int ans=0;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            while(sum>k){
                sum-=arr[j];
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
    
    int numSubarraysWithSum(vector<int>& arr, int k) {
        return atMostK(arr,k)-atMostK(arr,k-1);
    }    
};