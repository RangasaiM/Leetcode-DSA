class Solution {
public:

    int dfs(vector<int>& quiet,vector<vector<int>>& adj,int node,vector<int>& ans){

        if(ans[node]!=-1) return ans[node];

        int quiter=node;
        for(int i=0;i<adj[node].size();i++){
            int temp=dfs(quiet,adj,adj[node][i],ans);
            if(quiet[temp]<quiet[quiter]){
                quiter=temp;
            }
        }
        return ans[node]=quiter;
    }

    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<richer.size();i++){
            adj[richer[i][1]].push_back(richer[i][0]);
        }

        vector<int> ans(n,-1);

        for(int i=0;i<n;i++){
            ans[i]=dfs(quiet,adj,i,ans);
        }

        return ans;

    }
};