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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp= new ListNode(0,head);
     
        ListNode *prev=temp,*curr=head;

        while(curr){
            if(curr->next && curr->val==curr->next->val){
              while(curr->next && curr->val==curr->next->val){
                curr=curr->next;
              }
                prev->next=curr->next;
            }
            else{
            prev=curr;
            }
            curr=curr->next;
        }
        return temp->next;
    }
};