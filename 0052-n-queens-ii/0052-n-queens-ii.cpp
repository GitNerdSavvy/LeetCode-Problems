class Solution {
public:
     bool canPlace(int row,int col,vector<string>&grid,int n){
        for(int i=row-1;i>=0;i--){
            if(grid[i][col]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if(grid[i][j]=='Q'){
                return false;
            }
        }
        for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
            if(grid[i][j]=='Q'){
                return false;
            }
        }
        return true;
    }
     void solve(int n,vector<vector<string>>&out,vector<string>&nQ, int row){
        if(row==n){
            out.push_back(nQ);
            return;
        }
        for(int col=0;col<n;col++){
            if(canPlace(row,col,nQ,n)){
                nQ[row][col]='Q';
                solve(n,out,nQ,row+1);
                nQ[row][col]='.';
            }
        }
    }
    int totalNQueens(int n) {
         vector<vector<string>>out;
        vector<string> nQ(n, string(n, '.')); 
        solve(n,out,nQ,0);
        return out.size();
    }
};