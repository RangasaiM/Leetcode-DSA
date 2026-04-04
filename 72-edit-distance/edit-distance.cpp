class Solution {
public:
    int editDistanceMemo(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
         if (i == -1) return j + 1; 
         if (j == -1) return i + 1; 
         
        
         if (dp[i][j] != -1) return dp[i][j];
         
         if (s1[i] == s2[j]) {
             dp[i][j] = editDistanceMemo(i-1, j-1, s1, s2, dp); 
         } else {
             int insertOp = 1 + editDistanceMemo(i, j-1, s1, s2, dp); 
             int deleteOp = 1 + editDistanceMemo(i-1, j, s1, s2, dp); 
             int replaceOp = 1 + editDistanceMemo(i-1, j-1, s1, s2, dp); 
             
             dp[i][j] = min({insertOp, deleteOp, replaceOp});
         }
         
         return dp[i][j];
        }
        
    int minDistance(string s1, string s2) {
         int m = s1.size();
         int n = s2.size();
         vector<vector<int>> dp(m, vector<int>(n, -1));
         return editDistanceMemo(m-1, n-1, s1, s2, dp);
    }
};