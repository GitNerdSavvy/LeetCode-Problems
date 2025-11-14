class Solution {
public:
#define ll long long
    bool isPossible(vector<int>& target) {
        ll total = 0;
        priority_queue<ll> pq;

        for (int num : target) {
            pq.push(num);
            total += num;
        }

        while (pq.top() > 1) {
            ll mx = pq.top();
            pq.pop();
            ll rest = total - mx;
            if (rest == 0)
                return false;
            if (rest == 1)
                return true;
            ll curr = mx % rest;
            if (curr == 0 || curr == mx)
                return false;

            pq.push(curr);
            total = rest + curr;
        }

        return true;
    }
};