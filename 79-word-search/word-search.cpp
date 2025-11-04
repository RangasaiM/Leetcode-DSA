class Solution {
public:
    bool dfs(vector<vector<char>>& mat, string &s, int i, int j, int l, int n, int m, vector<vector<bool>> &vis) {
    if(i < 0 || j < 0 || i >= n || j >= m || mat[i][j] != s[l] || vis[i][j]) 
        return false;
    
    if(l == s.size() - 1) 
        return true;

    vis[i][j] = true;

    bool found = dfs(mat, s, i - 1, j, l + 1, n, m, vis) ||
                 dfs(mat, s, i + 1, j, l + 1, n, m, vis) ||
                 dfs(mat, s, i, j - 1, l + 1, n, m, vis) ||
                 dfs(mat, s, i, j + 1, l + 1, n, m, vis);

    vis[i][j] = false;

    return found;
}

    bool exist(vector<vector<char>>& mat, string s) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
    
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == s[0]) {
                    if(dfs(mat, s, i, j, 0, n, m, vis))
                        return true;
                }
            }
        }
        return false;
    }
};