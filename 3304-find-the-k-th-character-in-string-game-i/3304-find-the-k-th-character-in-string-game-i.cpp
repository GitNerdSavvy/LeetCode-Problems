class Solution {
public:
    void func(string& word, int k) {
        if (word.size() > k) {
            return;
        }
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (word[i] == 'z')
                word += 'a';
            else
                word += char(word[i] + 1);
        }
        func(word, k);
    }
    char kthCharacter(int k) {
        string word = "a";
        func(word, k);
        return word[k-1];
    }
};