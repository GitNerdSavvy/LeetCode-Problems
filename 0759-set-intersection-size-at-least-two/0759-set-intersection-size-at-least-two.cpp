class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), [](vector<int>& X, vector<int>& Y) {
            const int x0 = X[0], x1 = X[1], y0 = Y[0], y1 = Y[1];
            return (x1 == y1) ? x0 > y0 : x1 < y1;
        });

        int cnt = 2, n = arr.size();
        int b = arr[0][1], a = b - 1;

        for (int i = 1; i < n; i++) {
            const int l = arr[i][0], r = arr[i][1];

            if (a >= l)
                continue;

            const bool NO = (b < l);
            cnt += 1 + NO;
            a = NO ? r - 1 : b;
            b = r;
        }
        return cnt;
    }
};