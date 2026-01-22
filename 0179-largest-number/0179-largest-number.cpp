class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res = "";
        vector<string> s;
        for (auto it : nums)
            s.push_back(to_string(it));
        sort(s.begin(), s.end(), [](const string& a, const string& b) {
            return (b + a) < (a + b);
        });
        if (s[0] == "0")
            return "0";
        for (auto it : s) {
            res += it;
        }
        return res;
    }
};