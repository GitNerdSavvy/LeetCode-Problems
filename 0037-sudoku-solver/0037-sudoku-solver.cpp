class Solution {
public:
    bool isSafe(vector<vector<char>>&board,int r,int c,int num){
        for(int i=0;i<9;i++){
            if(board[r][i]-'0'==num) return false;
        }
        for(int i=0;i<9;i++){
            if(board[i][c]-'0'==num) return false;
        }
        int row=(r/3)*3;
        int col=(c/3)*3;
        for(int i=row;i<row+3;i++){
            for(int j=col;j<col+3;j++){
                if(board[i][j]-'0'==num) return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>&board,int r,int c){
        if(r==9) return true;
        if(c==9) return solve(board,r+1,0);
        if(board[r][c] !='.') return solve(board,r,c+1);

        for(int i=1;i<=9;i++){
            if(isSafe(board,r,c,i)){
                board[r][c]='0'+i;
                bool ans=solve(board,r,c+1);
                if(ans) return true;
                board[r][c] ='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};