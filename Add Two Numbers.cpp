class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sig=0;
        if(!l1)return l2;
        if(!l2)return l1;
        ListNode* head=l1;
        ListNode* pre1;ListNode* pre2;
        while(l1&&l2){
            int tep=l1->val+l2->val+sig;
            if(tep>9){
                sig=1;
                tep-=10;
            }
            else sig=0;
            l1->val=tep;
            pre1=l1;
            l1=l1->next;
            pre2=l2;
            l2=l2->next;
        }
        if(!l1){
            pre1->next=l2;
            l1=pre1->next;
        }
       while(sig){
           if(!l1){
               l1=new ListNode(0);
               pre1->next=l1;
           }
           int tep=l1->val+sig;
           if(tep>9){
               sig=1;
               tep-=10;
           }
           else sig=0;
           l1->val=tep;
           pre1=l1;
           l1=l1->next;
       }
       return head;
    }
};
