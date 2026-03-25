class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>>& adj, vector<int>& color) {
        color[node] = col;
        for (auto it : adj[node]) {
            if (color[it] == -1) {
                if (dfs(it, 1 - col, adj, color) == false)
                    return false;
            } else if (color[it] == color[node])
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& graph) {
        vector<vector<int>> adj(n + 1);
       for (auto& edge : graph) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> color(n+1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1) {
                if (dfs(i, 0, adj, color) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};