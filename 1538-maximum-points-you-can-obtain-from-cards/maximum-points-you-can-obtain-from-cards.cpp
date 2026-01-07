class Solution {
public:
    
    int maxScore(vector<int>& arr, int k) {
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int minSum=0;
        int ans=0;
        for(int i=0;i<n-k;i++){
            minSum+=arr[i];
        }
        ans=minSum;
        for(int i=n-k;i<n;i++){
            minSum+=arr[i];
            minSum-=arr[i-(n-k)];
            ans=min(ans,minSum);
        }
        return sum-ans;
    }
};