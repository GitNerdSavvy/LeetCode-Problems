class Solution {
public:
    bool dfs(int i, int j, int cnt, vector<vector<char>>& board, string word) {
        if (word.length() == cnt)
            return true;
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
            board[i][j] != word[cnt]) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = ' ';
        bool ans = dfs(i - 1, j, cnt + 1, board, word) ||
                   dfs(i + 1, j, cnt + 1, board, word) ||
                   dfs(i, j - 1, cnt + 1, board, word) ||
                   dfs(i, j + 1, cnt + 1, board, word);
        board[i][j] = temp;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && dfs(i, j, 0, board, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};