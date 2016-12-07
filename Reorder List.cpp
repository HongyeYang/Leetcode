class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head||!head->next||!head->next->next)return;
        ListNode* f=head;
        ListNode* s=head;
        while(f&&f->next){
            f=f->next->next;
            s=s->next;
        }
        ListNode* conv=s->next;
        ListNode* cpost=s;
        ListNode* cpre=conv->next;
        while(conv){
            cpre=conv->next;
            conv->next=cpost;
            cpost=conv;
            conv=cpre;
        }
        ListNode* l1=head;
        ListNode* l1pre=head->next;
        conv=cpost;
        cpre=conv->next;
        while(l1!=conv&&l1->next!=conv){
            l1->next=conv;
            conv->next=l1pre;
            l1=l1pre;
            l1pre=l1pre->next;
            conv=cpre;
            cpre=cpre->next;
        }
        conv->next=NULL;
        return;
    }
};
