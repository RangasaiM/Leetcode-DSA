class Solution {
public:

    vector<int> ind={1,0,-1,0,1};
    void bfs(vector<vector<int>>& image,int r,int c,int newColor,int n,int m,int val){
        queue<pair<int,int>> q;
        q.push({r,c});
        image[r][c]=newColor;
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int newi=temp.first+ind[i];
                int newj=temp.second+ind[i+1];
                if(newi>=0 && newi<n && newj>=0 && newj<m && image[newi][newj]==val){
                    image[newi][newj]=newColor;
                    q.push({newi,newj});
                }
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int r, int c,int newColor){
        int val = image[r][c];
        if (val == newColor) return image;
        bfs(image,r,c,newColor,image.size(),image[0].size(),image[r][c]);
        return image;
    }
};