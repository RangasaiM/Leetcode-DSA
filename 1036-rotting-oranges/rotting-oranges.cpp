class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> st;
        int ind[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
        int n=grid.size();
        int m=grid[0].size();
        int freshcnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    st.push({i,j});
                }
                if(grid[i][j]==1) freshcnt++;
            }
        }
        if(freshcnt==0) return 0;
        if(st.empty()) return -1;
        int ans=0;
        while(!st.empty()){
            int k=st.size();
            bool rottedThisMinute = false;
            while(k--){
                auto temp=st.front();
                st.pop();
                int i=temp.first;
                int j=temp.second;
                for(auto it:ind){
                    int newi=i+it[0];
                    int newj=j+it[1];
                    if((newi>=0 && newj>=0 && newi<n && newj<m) && grid[newi][newj]==1){
                        grid[newi][newj]=2;
                        freshcnt--;
                        st.push({newi,newj});
                        rottedThisMinute = true;
                    }
                }
            }
            if(rottedThisMinute)ans++;
            else break;
        }
        return (freshcnt == 0) ? ans : -1;
    }
};