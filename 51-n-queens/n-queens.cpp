class Solution {
public:


    vector<vector<string>> ans;

    bool isSafe(int n,vector<string>& board,int row,int col){
        int i=row,j=col;
        while(i>=0 && j>=0){
            if(board[i][j]=='Q') return false;
            i--;
            j--;
        }
        i=row,j=col;
        while(j>=0){
            if(board[i][j]=='Q') return false;
            j--;
        }
        i=row,j=col;
        while(i<n && j>=0){
            if(board[i][j]=='Q') return false;
            i++;
            j--;
        }
        return true;
    }
    

    void solve(int n,vector<string>& board,int row,int col){
        if(col==n){
            ans.push_back(board);
            return;
        }

        for(int i=0;i<n;i++){
            if(isSafe(n,board,i,col)){
                board[i][col]='Q';
                solve(n,board,0,col+1);
                board[i][col]='.';
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) board[i]=s;
        solve(n,board,0,0);
        return ans;
    }
};