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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* first=head;
        ListNode* sec=head->next;
        while(sec){
            ListNode* t=new ListNode(__gcd(first->val,sec->val));
            first->next=t;
            t->next=sec;
            first=sec;
            sec=sec->next;
        }
        return head;
    }
};