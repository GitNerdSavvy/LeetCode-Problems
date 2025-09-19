class Node {
    public:
    char data;
    bool term;
    unordered_map<char, Node*> ump;
    Node(char data) {
        this->data = data;
        this->term = false;
    }
    void makeT() { this->term = true; }
    bool isT() { return this->term; }
};
class Solution {
public:
    void insert(Node* head, string s) {
        Node* curr = head;
        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];
            if (curr->ump.count(ch)) {
                curr = curr->ump[ch];
            } else {
                Node* x = new Node(ch);
                curr->ump[ch] = x;
                curr = x;
            }
        }
        curr->makeT();
    }
    string func(Node* head, string s) {
        string res;
        Node* curr = head;
        for (int i = 0; i<s.length(); i++) {
            char ch = s[i];
            if (curr->ump.count(ch)) {
                res+=ch;
                curr = curr->ump[ch];
                if (curr->isT())
                    return res;
            } else {
                if (res == "" || i!=s.length())
                    return s;
                return res;
            }
        }
        return res;
    }
    string replaceWords(vector<string>& dict, string sentence) {
        string ans = "";
        Node* head = new Node('\0');
        for (int i = 0; i < dict.size(); i++) {
            insert(head, dict[i]);
        }
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            ans += func(head, word);
            ans += " ";
        }
        ans.erase(ans.length()-1);
        return ans;
    }
};