class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head||!head->next)return NULL;
        ListNode* f=head;
        ListNode* s=head;
        while(1){
            f=f->next->next;
            s=s->next;
            if(f==s)break;
            if(!f||!f->next)return NULL;
        }
        ListNode* kk=head;
        while(kk!=s){
            s=s->next;
            kk=kk->next;
        }
        return kk;
    }
};
