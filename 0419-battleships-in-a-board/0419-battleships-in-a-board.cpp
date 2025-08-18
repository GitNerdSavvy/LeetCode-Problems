class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        int cnt = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X') {
                    // board[i][j] = '.';
                    q.push({i, j});
                    cnt++;
                    while (!q.empty()) {
                        auto [row, col] = q.front();
                        q.pop();
                        for (int d = 0; d < 4; d++) {
                            int r = row + dir[d][0];
                            int c = col + dir[d][1];
                            if (r < 0 || c < 0 || r >= n || c >= m)
                                continue;
                            if (board[r][c] == '.')
                                continue;
                            board[r][c] = '.';
                            q.push({r,c});
                        }
                    }
                }
            }
        }
        return cnt;
    }
};