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
   ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode *list3=new ListNode(50);
        ListNode *t=list3;
        ListNode *list1=a;
        ListNode *list2=b;

        while(list1 && list2){
            if(list1->val<=list2->val){
                ListNode* t1=new ListNode(list1->val);
                t->next=t1;
                t=t1;
                list1=list1->next;
            }
            else{
                ListNode* t1=new ListNode(list2->val);
                t->next=t1;
                t=t1;
                list2=list2->next;
            }
        }
        if(list1==nullptr){
            t->next=list2;
        }else{
            t->next=list1;
        }
        return list3->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return nullptr;
        while(lists.size()>1){
            ListNode *a=lists[0];
            lists.erase(lists.begin());
            ListNode *b=lists[0];
            lists.erase(lists.begin());
            ListNode *c=mergeTwoLists(a,b);
            lists.push_back(c);
        }
        return lists[0];
    }
};