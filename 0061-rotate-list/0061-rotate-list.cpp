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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode *temp=head,*tail=nullptr;
        int n=0;
        while(temp){
            if(temp->next==nullptr) tail=temp;
            temp=temp->next;
            n++;
        }
        k=k%n;
        if (k == 0) return head;
          tail->next = head;
          temp = head;
        for(int i=0;i<n-k-1;i++){
            temp=temp->next;
        }
       
        head=temp->next;
        temp->next=nullptr;
        return head;
    }
};