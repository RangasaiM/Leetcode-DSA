class Solution {
public:

    vector<int> ind={0,-1,0,1,0};
    
    void dfs(vector<vector<int>>& grid,int i, int j){
        grid[i][j]=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int k=0;k<4;k++){
            int newi=i+ind[k];
            int newj=j+ind[k+1];
            if(newi>=0 && newj>=0 && newi<n && newj<m && grid[newi][newj]==1){
                grid[newi][newj]=0;
                dfs(grid,newi,newj);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<m;i++){
            if(grid[0][i]==1)
                dfs(grid,0,i);
                
            if(grid[n-1][i]==1)
                dfs(grid,n-1,i);
        }
        for(int i=0;i<n;i++){
            if(grid[i][0]==1)
                dfs(grid,i,0);
                
            if(grid[i][m-1]==1)
                dfs(grid,i,m-1);
        }
        

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) cnt++;
            }
        }
        return cnt;
    }

};