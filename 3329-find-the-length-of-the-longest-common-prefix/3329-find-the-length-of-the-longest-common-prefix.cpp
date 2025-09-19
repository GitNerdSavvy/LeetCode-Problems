class Node {
public:
    int data;
    unordered_map<int, Node*> ump;
    Node(int data) { this->data = data; }
};
class Solution {
public:
    void insert(Node* head, int data) {
        Node* curr = head;
        string temp = to_string(data);
        for (int i = 0; i < temp.length(); i++) {
            int d = temp[i] - '0';
            if (curr->ump.count(d)) {
                curr = curr->ump[d];
            } else {
                Node* newD = new Node(d);
                curr->ump[d] = newD;
                curr = newD;
            }
        }
    }
    int func(Node* head, int data) {
        Node* curr = head;
        int ans = 0;
        string temp = to_string(data);
        for (int i = 0; i < temp.length(); i++) {
            int d = temp[i] - '0';
            if (curr->ump.count(d)) {
                ans++;
                curr = curr->ump[d];
            } else {
                break;
            }
        }
        return ans;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        Node* head = new Node(-1);
        for (int i = 0; i < arr1.size(); i++) {
            insert(head, arr1[i]);
        }
        for (int i = 0; i < arr2.size(); i++) {
            ans = max(ans, func(head, arr2[i]));
        }
        return ans;
    }
};