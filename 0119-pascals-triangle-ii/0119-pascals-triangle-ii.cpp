class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int pass[35][35] = {0};
        pass[0][0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    pass[i][j] = 1;
                else
                    pass[i][j] = pass[i - 1][j] + pass[i - 1][j - 1];
            }
        }
        vector<int> ans(rowIndex + 1);
        for (int i = 0; i <= rowIndex; i++) {
            ans[i] = pass[rowIndex][i];
        }
        return ans;
    }
};