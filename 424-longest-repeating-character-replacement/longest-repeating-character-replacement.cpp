class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        unordered_map<char,int> mp;
        int ans=0;
        int maxf=0;
        int j=0;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
            maxf=max(maxf,mp[s[i]]);
            if((i-j+1)-maxf>k){
                mp[s[j]]--;
                // maxf=findMaxf(mp);
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};