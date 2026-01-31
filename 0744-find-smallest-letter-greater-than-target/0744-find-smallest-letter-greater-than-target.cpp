class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0, h = letters.size() - 1;
        char ans = letters[0];
        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (letters[mid] > target) {
                ans = letters[mid];
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};