class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size(), sum = 0;

        for (int i = 1; i < n; i++) {
            int mx = 0;
            while (i < n and colors[i] == colors[i - 1]) {
                sum += neededTime[i - 1];
                mx = max(mx, neededTime[i - 1]);
                ++i;
            }
            sum += neededTime[i - 1];
            mx = max(mx, neededTime[i - 1]);
            if (mx != 0)
                sum -= mx;
        }
        return sum;
    }
};