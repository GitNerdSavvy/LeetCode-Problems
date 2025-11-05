class Solution {
    bool isReplaceable(auto& PQ, auto& remPQ) {
        auto [freq1, curr1] = *PQ.begin();
        auto [freq2, curr2] = *remPQ.rbegin();
        return freq2 > freq1 || (freq2 == freq1 && curr2 > curr1);
    }
    void remove(int num, long long& sum, set<pair<int, int>>& PQ,
                set<pair<int, int>>& remPQ, int freq) {
        auto iter = PQ.find(make_pair(freq, num));
        auto remIter = remPQ.find(make_pair(freq, num));
        if (iter != PQ.end()) {
            sum -= freq * 1LL * num;
            PQ.erase(iter);
        } else if (remIter != remPQ.end()) {
            remPQ.erase(remIter);
        }
    }
    void balance(int num, long long& sum, set<pair<int, int>>& PQ,
                 set<pair<int, int>>& remPQ, int freq, int x) {
        while (PQ.size() < x && !remPQ.empty()) {
            auto [freq1, curr1] = *remPQ.rbegin();
            PQ.insert({freq1, curr1});
            sum += freq1 * 1LL * curr1;
            remPQ.erase(--remPQ.end());
        }
        while (PQ.size() == x && !remPQ.empty() && isReplaceable(PQ, remPQ)) {
            auto [freq1, curr1] = *PQ.begin();
            auto [freq2, curr2] = *remPQ.rbegin();
            PQ.erase(PQ.begin());
            remPQ.erase(--remPQ.end());
            PQ.insert({freq2, curr2});
            remPQ.insert({freq1, curr1});
            sum -= freq1 * 1LL * curr1;
            sum += freq2 * 1LL * curr2;
        }
    }

public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        vector<long long> ans;
        unordered_map<int, int> freq;
        set<pair<int, int>> PQ, remPQ;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            remove(nums[i], sum, PQ, remPQ, freq[nums[i]]);
            freq[nums[i]]++;
            remPQ.insert({freq[nums[i]], nums[i]});
            balance(nums[i], sum, PQ, remPQ, freq[nums[i]], x);
            if (i >= k) {
                remove(nums[i - k], sum, PQ, remPQ, freq[nums[i - k]]);
                freq[nums[i - k]]--;
                if (freq[nums[i - k]] == 0) {
                    freq.erase(nums[i - k]);
                } else {
                    remPQ.insert({freq[nums[i - k]], nums[i - k]});
                }
                balance(nums[i - k], sum, PQ, remPQ, freq[nums[i - k]], x);
            }
            if (i >= k - 1) {
                ans.push_back(sum);
            }
        }
        return ans;
    }
};