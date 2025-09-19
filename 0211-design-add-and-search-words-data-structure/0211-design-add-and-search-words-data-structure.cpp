class Node {
public:
    char data;
    bool terminal;
    unordered_map<char, Node*> ump;
    Node(char data) {
        this->data = data;
        this->terminal = false;
    }
    void makeT() { this->terminal = true; }
    bool isT() { return this->terminal; }
};
class WordDictionary {
public:
    Node* root;
    WordDictionary() { root = new Node('\0'); }
    void addWord(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (curr->ump.count(ch)) {
                curr = curr->ump[ch];
            } else {
                Node* w = new Node(ch);
                curr->ump[ch] = w;
                curr = w;
            }
        }
        curr->makeT();
    }
    bool search(string word) {
       return search1(word,0,root);
    }
    private:
     bool search1(string &word, int index, Node* node) {
        if (index == word.size()) return node->isT();

        char ch = word[index];
        if (ch == '.') {
            for (auto &p : node->ump) {
                if (search1(word, index + 1, p.second)) return true;
            }
            return false;
        } else {
            if (!node->ump.count(ch)) return false;
            return search1(word, index + 1, node->ump[ch]);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */