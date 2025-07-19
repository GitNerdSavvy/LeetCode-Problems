class Solution {
public:
    typedef pair<int, int> pi;
    struct cmp {
    bool operator()(pi a, pi b) {
        if (a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> v;
        for (int i : nums) {
            mp[i]++;
        }
        priority_queue<pi, vector<pi>, cmp> pq;
        for (auto x : mp) {
            pq.push({x.second, x.first});
        }
        while (!pq.empty()) {
            int j=pq.top().first;
            while (j--) {
                v.push_back(pq.top().second);
            }
            pq.pop();
        }
        return v;
    }
};