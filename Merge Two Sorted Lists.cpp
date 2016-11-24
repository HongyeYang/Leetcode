class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1)return l2;
        if(!l2)return l1;
         if(l1->val>l2->val){
            ListNode* tep=l1;
            l1=l2;
            l2=tep;
        }
        ListNode* t1=l1;
        ListNode* t2=l2;
        ListNode* t1post=l1;
        while(t1&&t2){
            if(t1->val<=t2->val){
                t1post=t1;
                t1=t1->next;
            }
            else{
                t1post->next=t2;
                ListNode* tep=t2;
                t2=t2->next;
                tep->next=t1;
                t1post=tep;
            }
        }
        if(!t1)t1post->next=t2;
        return l1;
    }
};
