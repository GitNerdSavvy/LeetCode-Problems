class Solution {
public:
    bool dfs(int curr, int end, vector<vector<int>>& adj,
             unordered_set<int>& visited) {
        if (curr == end)
            return true;
        visited.insert(curr);
        for (int neighbor : adj[curr]) {
            if (!visited.count(neighbor) && dfs(neighbor, end, adj, visited))
                return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> visited;
        return dfs(source, destination, adj, visited);
    }
};