class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i>0 && arr[i-1]==arr[i]) continue;
            int j=i+1;
            int end=n-1;
            while(j<end){
                int val=arr[i]+arr[j]+arr[end];
                if(val==0){
                    ans.push_back({arr[i],arr[j],arr[end]});
                    while(j<end && arr[j]==arr[j+1]) j++;
                    while(j<end && arr[end-1]==arr[end]) end--;
                    j++;
                    end--;
                }
                else if(val>0) end--;
                else j++;
            }
        }
        return ans;
    }
};