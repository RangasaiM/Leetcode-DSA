class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int ans=0;
        int cnt=0;
        for(int i=1;i<n-1;i++){
            if(arr[i-1]<arr[i] && arr[i+1]<arr[i]){
                cnt=1;
                int j=i-1;
                int k=i;
                while(j>=0 && arr[j]<arr[j+1]){
                    j--;
                    cnt++;
                }
                while(k<n-1 && arr[k]>arr[k+1]){
                    k++;
                    cnt++;
                }
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};