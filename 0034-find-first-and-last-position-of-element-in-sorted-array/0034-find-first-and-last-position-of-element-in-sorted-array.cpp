class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        auto low = lower_bound(arr.begin(), arr.end(), target);
        auto high = upper_bound(arr.begin(), arr.end(), target);

        if (low == arr.end() || *low != target)
            return {-1, -1};

        return {int(low - arr.begin()), int(high - arr.begin()) - 1};
    }
};