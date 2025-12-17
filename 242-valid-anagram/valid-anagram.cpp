class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> mp(26,0);
        for(int i=0;i<s.length();i++){
            mp[s[i]-'a']++;
        }
        for(int i=0;i<t.length();i++){
            mp[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(mp[i]!=0) return false;
        }
        return true;
    }
};