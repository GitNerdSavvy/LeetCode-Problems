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
    ListNode* swapNodes(ListNode* head, int k) {
       ListNode *prev=head,*curr=head;
        for(int i=1;i<k;i++){
            curr=curr->next;
        }
       
       ListNode *ptr =curr;
       while(ptr->next){
        ptr=ptr->next;
        prev=prev->next;
       }
       
        int d=prev->val;
        prev->val=curr->val;
        curr->val=d;
        return head;


    }
};