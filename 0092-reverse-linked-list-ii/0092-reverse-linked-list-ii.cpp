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
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(!head || l==r) return head;

        ListNode *t= new ListNode(0);
        t->next=head;
        ListNode *prev=t;

        for(int i=0;i<l-1;i++){
            prev=prev->next;
        }

        ListNode *cur =prev->next;
        for(int i=0;i<r-l;i++){
            ListNode *temp=cur->next;
            cur->next=temp->next;
            temp->next=prev->next;
            prev->next=temp;
        }

        return t->next;
    }
};