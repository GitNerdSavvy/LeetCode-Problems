class Solution {
public:
 long long pickGifts(vector<int>& gifts, long long k) {
        priority_queue<long long> pq;
        for (int val : gifts) {
        pq.push(val);
         }

        while (k--) {
            long long temp = sqrt(pq.top());
            pq.pop();
            pq.push(temp);
        }
        long long ans = 0;
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};