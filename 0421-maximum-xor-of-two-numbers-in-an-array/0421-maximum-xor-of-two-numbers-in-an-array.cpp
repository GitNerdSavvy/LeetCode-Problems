class Node {
    public:
    Node* left;
    Node* right;
    Node() { this->left = this->right = NULL; }
};
class Solution {
public:
    int maxX(Node* head, int data) {
        Node* curr = head;
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (data >> i) & 1;
            if (bit == 0) {
                if (curr->right) {
                    curr = curr->right;
                    ans += (1 << i);
                } else {
                    curr = curr->left;
                }
            } else {
                if (curr->left) {
                    curr = curr->left;
                    ans += (1 << i);
                } else {
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
    void insert(Node* head, int data) {
        Node* curr = head;
        for (int i = 31; i >= 0; i--) {
            int bit = (data >> i) & 1;
            if (bit == 0) {
                if (!curr->left) {
                    curr->left = new Node();
                }
                curr = curr->left;
            } else {
                if (!curr->right) {
                    curr->right = new Node();
                }
                curr = curr->right;
            }
        }
    }
    int findMaximumXOR(vector<int>& nums) {
        Node* head = new Node();
        int ans = 0;
        insert(head, nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            insert(head, nums[i]);
            ans = max(ans, maxX(head, nums[i]));
        }
        return ans;
    }
};