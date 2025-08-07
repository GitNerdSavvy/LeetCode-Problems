class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(int node, int target, vector<vector<int>>& graph) {
        path.push_back(node);
        if (node == target) {
            res.push_back(path);
        } else {
            for (int neighbor : graph[node]) {
                dfs(neighbor, target, graph);
            }
        }
        path.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        res.clear();
        path.clear();
        int target = graph.size() - 1;
        dfs(0, target, graph);
        return res;
    }
};