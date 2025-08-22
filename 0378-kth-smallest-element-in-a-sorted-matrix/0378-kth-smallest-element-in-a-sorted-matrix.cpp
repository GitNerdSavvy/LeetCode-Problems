class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            pq;

        for (int i = 0; i < n; i++) {
            pq.push({matrix[i][0], {i, 0}});
        }

        int ans = -1;
        while (k--) {
            auto [i, j] = pq.top();
            pq.pop();
            ans = i;
            int r = j.first, c = j.second;
            if (c + 1 < n) {
                pq.push({matrix[r][c + 1], {r, c + 1}});
            }
        }
        return ans;
    }
};