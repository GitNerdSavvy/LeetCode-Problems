/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
     ListNode* reverseList(ListNode* head) {
        ListNode *c,*p=nullptr;
        while(head){
            c=head->next;
            head->next=p;
            p=head;
            head=c;
        }
        return p;
    }
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> s;

        head = reverseList(head);
        
        ListNode* ptr = head;
        while (ptr) {
          while (!s.empty() && s.top() <= ptr->val) {
                s.pop();
            }
            if (s.empty()) {
                ans.push_back(0);
            } else {
                ans.push_back(s.top());
            }
            s.push(ptr->val);
            ptr = ptr->next;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};