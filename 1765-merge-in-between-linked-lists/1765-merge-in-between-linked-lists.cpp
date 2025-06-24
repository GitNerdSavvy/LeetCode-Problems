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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* ptr=list1;

        for(int i=1;i<a;i++){
            ptr=ptr->next;
        }
        ListNode* t=list1;
        for(int i=0;i<b;i++){
            t=t->next;
        }
        ListNode* p1=list2;
        ptr->next=list2;

        while(p1->next){
            p1=p1->next;
        }
        p1->next=t->next;
        return list1;

    }
};