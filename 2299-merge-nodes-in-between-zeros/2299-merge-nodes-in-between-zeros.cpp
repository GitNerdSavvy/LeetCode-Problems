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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *left=head->next;
        while(left){
            ListNode *right=left;
            int sum=0;
            while(right->val!=0){
                sum+=right->val;
                right=right->next;
            }
            left->val=sum;
            left->next=right->next;
            left=left->next;
        }
        return head->next;
    }
};