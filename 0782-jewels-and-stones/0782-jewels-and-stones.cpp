class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int c=0;
        unordered_map<char,int>ans;
        for(int i=0;i<stones.length();i++){
           ans[stones[i]]++;
        }
        for (char j : jewels) {
        c += ans[j];
    }
    return c;
    }
};