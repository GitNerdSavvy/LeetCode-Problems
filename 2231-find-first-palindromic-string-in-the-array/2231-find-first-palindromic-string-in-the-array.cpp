class Solution {
public:
   bool isPalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

string firstPalindrome(vector<string>& words) {
    for (int i = 0; i < words.size(); i++) {
        if (isPalindrome(words[i])) {
            return words[i];
        }
    }
    return "";
    }
};