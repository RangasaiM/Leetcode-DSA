class Solution {
public:
int atMost(int n, vector<int>& arr, int k){
        unordered_map<int,int> mp;
        int ans=0;
        int j=0;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            while(mp.size()>k){
                mp[arr[j]]--;
                if(mp[arr[j]]==0) mp.erase(arr[j]);
                j++;
                
            }
            ans+=i-j+1;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& arr, int k) {
        int n=arr.size();
        return atMost(n,arr,k)-atMost(n,arr,k-1);
    }
};