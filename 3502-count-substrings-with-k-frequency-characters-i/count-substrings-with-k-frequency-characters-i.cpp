class Solution {
public:
    int numberOfSubstrings(string s, int k) {
        unordered_map<char,int> mp;
        int i=0,j=0;
        long long cnt=0;
        int n=s.length();
        int maxi=0;
        for (int i = 0; i < n; i++) {
           mp[s[i]]++;
            maxi=max(maxi,mp[s[i]]);
           
           while(j<s.size() && maxi>=k){
               cnt+=(n-i);
               
               mp[s[j]]--;
               if(mp[s[j]]==0) mp.erase(s[j]);
               j++;

               maxi=0;

               for(auto p:mp){
                maxi=max(maxi,p.second);
               }
           }
        }
        return cnt;
    }
};