class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head||!head->next||!head->next->next)return head;
        ListNode* l1=head;
        ListNode* l2=head->next;
        ListNode* head2=l2;
        ListNode* p1=l2->next;
        ListNode* p2=p1->next;
        while(1){
            l1->next=p1;
            l2->next=p2;
            l1=p1;
            l2=p2;
            if(!l2)break;
            p1=l2->next;
            if(!p1)break;
            p2=p1->next;
        }
        l1->next=head2;
        return head;
    }
};
