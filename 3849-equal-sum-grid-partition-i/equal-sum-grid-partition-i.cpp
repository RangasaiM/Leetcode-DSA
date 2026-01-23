class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum=0;
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
            }
        }

        if(sum%2) return false;

        long long rowSum=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rowSum+=grid[i][j];
            }
            if(rowSum==sum/2) return true;
        }

        long long colSum=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                colSum+=grid[j][i];
            }
            if(colSum==sum/2) return true;
        }

        return false;
    }
};