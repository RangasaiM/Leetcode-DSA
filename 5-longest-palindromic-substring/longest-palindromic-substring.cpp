class Solution {
public:

    string expand(string s,int i,int j){
        int n=s.length();
        while(i>=0 && j<n && s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-i-1);
    }

    string longestPalindrome(string s) {
        int n=s.size();
        string ans="";

        for(int i=0;i<n;i++){
            string odd=expand(s,i,i);
            if(ans.length()<odd.length()) ans=odd;
            string even=expand(s,i,i+1);
            if(ans.length()<even.length()) ans=even;
        }
        return ans;
        
    }
};