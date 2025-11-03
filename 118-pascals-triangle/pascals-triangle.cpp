class Solution {
public:

    vector<int> nthRow(int n){
        vector<int> row;
        int curr=1;
        row.push_back(curr);
        for (int i=1;i<n;i++){
            curr*=(n-i);
            curr=curr/i;
            row.push_back(curr);
        }
        return row;
    }

    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>> ans;
        for (int i=0;i<n;i++){
            ans.push_back(nthRow(i+1));
        }
        return ans;
    }

};