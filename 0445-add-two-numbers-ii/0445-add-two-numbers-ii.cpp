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

    ListNode* insertathead(ListNode* list, int x) {
        ListNode* newNode = new ListNode(x);
        newNode->next = list;
        return newNode;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;

        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* res = nullptr;
        int carry = 0;
        
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            carry = sum / 10;
            sum = sum % 10;
            res = insertathead(res, sum);
        }
        
        return res;
    }
};