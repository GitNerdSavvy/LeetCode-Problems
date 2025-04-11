class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        unordered_map<char,int>ans;
        if(word1.length()!=word2.length()) return false;
        for(int i=0;i<word1.length();i++){
            ans[word1[i]]++;
            ans[word2[i]]--;
        }
        for(auto i:ans){
            if(abs(i.second)>3){
                return false;
            }
        }
        return true;
    }
};