class Solution {
public:
    bool dfs(vector<vector<char>>& mat, string &s, int i, int j, int l, int n, int m) {
    if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != s[l]) 
        return false;
    
    if(l == s.size() - 1) 
        return true;

    char temp=mat[i][j];
    mat[i][j]='#';

    bool found = dfs(mat, s, i - 1, j, l + 1, n, m) ||
                 dfs(mat, s, i + 1, j, l + 1, n, m) ||
                 dfs(mat, s, i, j - 1, l + 1, n, m) ||
                 dfs(mat, s, i, j + 1, l + 1, n, m);

    mat[i][j] = temp;

    return found;
}

    bool exist(vector<vector<char>>& mat, string s) {
        int n = mat.size();
        int m = mat[0].size();
    
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == s[0]) {
                    if(dfs(mat, s, i, j, 0, n, m))
                        return true;
                }
            }
        }
        return false;
    }
};