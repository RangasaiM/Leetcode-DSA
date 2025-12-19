class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n));
        int maxLen=0;
        int st=0;
        for(int i=0;i<n;i++) dp[i][i]=1;
        for(int i=0;i<n-1;i++) {
            if(s[i]==s[i+1]){
             dp[i][i+1]=1;
             maxLen=1;
             st=i;
            }
            else dp[i][i+1]=0;
        }

        for(int i=2;i<n;i++){
            for(int j=0;j<n-i;j++){
                if(s[j]==s[j+i]){
                    dp[j][j+i]=dp[j+1][j+i-1];
                    if(dp[j][j+i]==1){
                        maxLen=i;
                        st=j;
                    }
                }
                else dp[j][j+i]=0;
            }
        }
        return s.substr(st,maxLen+1);
    }
};