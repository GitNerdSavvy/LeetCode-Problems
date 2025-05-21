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
    ListNode* partition(ListNode* head, int x) {
        ListNode *small=new ListNode(0);
        ListNode *large=new ListNode(0);
        ListNode *t=small,*t1=large;
        ListNode *curr=head;
        while(curr){
            if(curr->val < x){
                small->next=curr;
                small=small->next;
                curr=curr->next;
                small->next=nullptr;
            }else{
                large->next=curr;
                large=large->next;
                curr=curr->next;
                large->next=nullptr;

            }
        }
        small->next=t1->next;
        return t->next;
    }
};