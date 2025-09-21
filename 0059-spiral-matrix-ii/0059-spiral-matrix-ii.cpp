class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>grid(n,vector<int>(n));
        int c=1;
        // vector<vector<int>> ans;
        // for(int i=1;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         grid[i][j]=c++;
        //     }
        // }
        int top=0,right=n-1,left=0,down=n-1;
        while(top<=down && left<=right){
            for(int i=left;i<=right;i++){
                grid[top][i]=c++;
            }
            top++;
            for(int i=top;i<=down;i++){
                grid[i][right]=c++;
            }
            right--;
            if(left<=right){
                for(int i=right;i>=left;i--){
                    grid[down][i]=c++;
                }
                down--;
            }
            if(top<=down){
                for(int i=down;i>=top;i--){
                    grid[i][left]=c++;
                }
                left++;
            }
        }
        return grid;
    }
};