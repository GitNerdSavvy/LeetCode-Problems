class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> s(arr.begin(), arr.end());
        int ans = 0;

        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j<arr.size(); j++) {
                int x = arr[i], y = arr[j];
                int cnt = 2;
                while (s.find(x + y) != s.end()) {
                    int z = x + y;
                    x = y;
                    y = z;
                    cnt++;
                }
                if (cnt >= 3)
                    ans = max(ans, cnt);
            }
        }
        return ans;
    }
};