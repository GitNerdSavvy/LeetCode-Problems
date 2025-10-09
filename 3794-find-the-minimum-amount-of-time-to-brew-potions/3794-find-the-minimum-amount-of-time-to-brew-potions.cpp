class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> ans(n + 1, 0);
        
        for (int j = 0; j < m; ++j) {
            for (int i = 0; i < n; ++i) {
                ans[i + 1] = max(ans[i + 1], ans[i]) + 1LL * mana[j] * skill[i];
            }
            for (int i = n - 1; i > 0; --i) {
                ans[i] = ans[i + 1] - 1LL * mana[j] * skill[i];
            }
        }
        
        return ans[n];
    }
};