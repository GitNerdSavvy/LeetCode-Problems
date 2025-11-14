class Solution {
public:
    typedef pair<int, int> pi;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        vector<vector<int>> res;
        if (nums1.empty() || nums2.empty() || k == 0)
            return res;

        auto cmp = [&](pair<int, int>& a, pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] >
                   nums1[b.first] + nums2[b.second];
        };

        priority_queue<pi, vector<pi>, decltype(cmp)>
            pq(cmp);
        pq.push({0, 0});

        set<pair<int, int>> vis;
        vis.insert({0, 0});

        while (!pq.empty() && res.size() < k) {
            auto [i, j] = pq.top();
            pq.pop();
            res.push_back({nums1[i], nums2[j]});

            if (i + 1 < nums1.size() && !vis.count({i + 1, j})) {
                pq.push({i + 1, j});
                vis.insert({i + 1, j});
            }
            if (j + 1 < nums2.size() && !vis.count({i, j + 1})) {
                pq.push({i, j + 1});
                vis.insert({i, j + 1});
            }
        }

        return res;
    }
};