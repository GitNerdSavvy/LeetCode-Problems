class Solution {
public:
    string reversePrefix(string word, char ch) {
        int k=word.find(ch);
        reverse(word.begin(),word.begin()+k+1);
        return word;
    }
};