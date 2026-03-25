class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> adj[v];
        vector<int> outdegree(v, 0);
        queue<int> q;
        for (int i = 0; i < v; i++) {
            for (int neighbor : graph[i]) {
                adj[neighbor].push_back(i);
            }
            outdegree[i] = graph[i].size();
            if (outdegree[i] == 0)
                q.push(i);
        }

        vector<int> safe(v);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = 1;
            for (int it : adj[node]) {
                outdegree[it]--;
                if (outdegree[it] == 0)
                    q.push(it);
            }
        }
        vector<int> ans;
        for (int i = 0; i < v; i++) {
            if (safe[i])
                ans.push_back(i);
        }
        return ans;
    }
};