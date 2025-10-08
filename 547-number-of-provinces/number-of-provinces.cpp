class Solution {
public:

    void bfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int i = 0; i < isConnected.size(); i++) {
                if (isConnected[curr][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bfs(i, isConnected, visited);
                provinces++;
            }
        }
        return provinces;
    }
};