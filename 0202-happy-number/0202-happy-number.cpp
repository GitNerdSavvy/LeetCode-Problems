class Solution {
public:
    bool rec(string s,unordered_set<int> &seen) {
        int num = stoi(s);
        if (num == 1)
            return true;
        if (seen.count(num))
            return false;
        seen.insert(num);

        int sum = 0;
        for (char c : s) {
            int d = c - '0';
            sum += d * d;
        }

        return rec(to_string(sum), seen);
    }
    bool isHappy(int n) {
        if (n <= 0)
            return false;
        unordered_set<int> seen;
        return rec(to_string(n), seen);
    }
};