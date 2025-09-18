class Node {
public:
    char data;
    bool Terminal;
    unordered_map<char, Node*> ump;
    Node(char data) {
        this->data = data;
        this->Terminal = false;
    }
    void makeTerminal() { this->Terminal = true; }
    bool isTerminal() { return this->Terminal; }
};

class Trie {
public:
    Node* root;
    Trie() { root = new Node('\0'); }
    void insert(string word) {
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
        curr->makeTerminal();
    }
    bool search(string word) {
        Node* curr = root;
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            if (curr->ump.count(ch)) {
                curr = curr->ump[ch];
            } else {
                return false;
            }
        }
        return curr->isTerminal();
    }

    bool startsWith(string prefix) {
        Node* curr = root;
        for (int i = 0; i < prefix.size(); i++) {
            char ch = prefix[i];
            if (curr->ump.count(ch)) {
                curr = curr->ump[ch];
            } else {
                return false;
            }
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */