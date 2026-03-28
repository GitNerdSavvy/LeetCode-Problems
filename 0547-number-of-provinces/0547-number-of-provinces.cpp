class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                queue<int> q;
                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int v = 0; v < isConnected.size(); v++) {
                        if (isConnected[node][v] == 1 && !visited[v]) {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
                cnt++;
            }
        }
        return cnt;
    }
};