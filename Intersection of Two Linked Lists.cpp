class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA||!headB)return NULL;
        ListNode* l1=headA;
        ListNode* l2=headB;
        while(l1&&l2){
            l1=l1->next;
            l2=l2->next;
        }
        if(l1){
            ListNode* tep=headB;
            headB=headA;
            headA=tep;
            l2=l1;
        }
        l1=headB;
        while(l2){
            l1=l1->next;
            l2=l2->next;
        }
        l2=headA;
        while(l1&&l2){
            if(l1==l2)return l1;
            l1=l1->next;
            l2=l2->next;
        }
        return NULL;
    }
};
