class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res=new ListNode();
        ListNode* t=res;
        int carry=0;
        while(l1 || l2 || carry){
            int sum=0;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* v=new ListNode(sum%10);
            t->next=v;
            t=t->next;
        }
        return res->next;
    }
};