class Solution {
public:
    int kthGrammar(int n, int k) {
      int flips = __builtin_popcount(k - 1);
        return flips % 2;
    }
};