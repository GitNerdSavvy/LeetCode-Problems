class Solution {
public:
    int maxRepOpt1(string text) {
        int n = text.size();
        unordered_map<char, int> c;
        for (char ch : text)
            c[ch]++;

        vector<int> repeated(n, 1);
        for (int k = 1; k < n; k++) {
            if (text[k] == text[k - 1]) {
                repeated[k] = repeated[k - 1] + 1;
            }
        }

        int i = n - 1;
        int maxx = 1;

        while (i >= 0) {
            int currmax = repeated[i];
            int prevrp = i - repeated[i] - 1;

            if (prevrp >= 0 && text[i] == text[prevrp]) {
                currmax += repeated[i - currmax - 1];
            }

            if (c[text[i]] > currmax) {
                currmax += 1;
            }

            maxx = max(maxx, currmax);
            i -= repeated[i];
        }

        return maxx;
    }
};