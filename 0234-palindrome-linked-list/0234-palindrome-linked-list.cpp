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
   ListNode* reverse(ListNode* head) {
        ListNode *c, *p = nullptr;
        while (head) {
            c = head->next;
            head->next = p;
            p = head;
            head = c;
        }
        return p;
}

    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast) {
            slow = slow->next;
        }

        ListNode* middle = reverse(slow);
        ListNode* h = head;

        while (middle) {
            if (h->val != middle->val) return false;
            h = h->next;
            middle = middle->next;
        }

        return true;
    }

};