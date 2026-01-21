class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});

        string ans = "";
        while (!pq.empty()) {
            auto [count1, ch1] = pq.top();
            pq.pop();

            if (ans.size() >= 2 && ans[ans.size() - 1] == ch1 &&
                ans[ans.size() - 2] == ch1) {
                if (pq.empty())
                    break;
                auto [count2, ch2] = pq.top();
                pq.pop();
                ans.push_back(ch2);
                if (--count2 > 0)
                    pq.push({count2, ch2});
                pq.push({count1, ch1});
            } else {
                ans.push_back(ch1);
                if (--count1 > 0)
                    pq.push({count1, ch1});
            }
        }
        return ans;
    }
};