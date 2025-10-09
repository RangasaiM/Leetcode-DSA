class Solution {
public:

    vector<int> ind={1,0,-1,0,1};
    void bfs(vector<vector<int>>& grid,vector<vector<bool>>& vis,vector<vector<int>>& agrid,queue<tuple<int,int,int>>& q,int n,int m){
        while(!q.empty()){
            int r=q.size();
            while(r--){
                auto temp=q.front();
                q.pop();
                int row=get<0>(temp);
                int col=get<1>(temp);
                int g=get<2>(temp);
                agrid[row][col]=min(agrid[row][col],g);
                for(int k=0;k<4;k++){
                    int newi=row+ind[k];
                    int newj=col+ind[k+1];
                    if(newi>=0 && newj>=0 && newi<n && newj<m && !vis[newi][newj]){
                        vis[newi][newj]=true;
                        q.push({newi,newj,g+1});
                    }
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& grid){
        vector<vector<int>> agrid(grid.size(),vector<int>(grid[0].size(),INT_MAX));
        queue<tuple<int,int,int>> q;
        vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0){
                    q.push({i,j,0});
                }
            }
        }
        bfs(grid,vis,agrid,q,grid.size(),grid[0].size());
        return agrid;
    }

};