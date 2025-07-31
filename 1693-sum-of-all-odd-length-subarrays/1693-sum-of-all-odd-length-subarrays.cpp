class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int ts = (i + 1) * (n - i);
            int cnt = (ts + 1) / 2;
            sum += arr[i] * cnt;
        }
        return sum;
    }
};