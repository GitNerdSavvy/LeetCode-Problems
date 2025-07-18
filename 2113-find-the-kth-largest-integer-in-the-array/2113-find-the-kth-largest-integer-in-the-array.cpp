class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        auto cmp = [](const string& a, const string& b) {
            if (a.size() != b.size())
                return a.size() > b.size();
            return a > b;
        };

        priority_queue<string, vector<string>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
            if (pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};