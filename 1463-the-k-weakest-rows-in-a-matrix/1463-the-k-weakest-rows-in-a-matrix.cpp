class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int, int>> v;
        for (int i = 0; i < m; i++) {
            int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
            v.push_back({sum, i});
        }
        sort(v.begin(), v.end());
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(v[i].second);
        }
        return result;
    }
};