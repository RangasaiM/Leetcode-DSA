class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int> mp;
            for(int j=i;j<n;j++){
                int mini=INT_MAX;
                int maxi=INT_MIN;
                mp[s[j]]++;
                for(auto it:mp){
                    mini=min(mini,it.second);
                    maxi=max(maxi,it.second);
                }
            ans+=(maxi-mini);
            }
        }
        return ans;
    }
};