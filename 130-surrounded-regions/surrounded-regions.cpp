class Solution {
public:
    vector<int> ind={0,-1,0,1,0};
    
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>& vis,int n,int m,int i,int j){
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int row=i+ind[k];
            int col=j+ind[k+1];
            if(row>=0 && col>=0 && row<n && col<m && grid[row][col]=='O' && !vis[row][col] ){
                dfs(grid,vis,n,m,row,col);
            }
        }
    }

    void solve(vector<vector<char>>& grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            if(!vis[i][0] && grid[i][0]=='O')
                dfs(grid,vis,n,m,i,0);
            if(!vis[i][m-1] && grid[i][m-1]=='O')
                dfs(grid,vis,n,m,i,m-1);
        }
        
        for(int i=0;i<m;i++){
            if(!vis[0][i] && grid[0][i]=='O')
                dfs(grid,vis,n,m,0,i);
            if(!vis[n-1][i] && grid[n-1][i]=='O')
                dfs(grid,vis,n,m,n-1,i);
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='O'){
                    grid[i][j]='X';
                }
            }
        }
    }
};