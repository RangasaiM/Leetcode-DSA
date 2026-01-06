class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n=arr.size();
        int ans=0;
        int zeroCnt=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(arr[i]==0){
                zeroCnt++;
            }
            while(zeroCnt>k){
                if(arr[j]==0) zeroCnt--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};