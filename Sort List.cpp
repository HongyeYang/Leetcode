class Solution {
public:
    ListNode* Merge(ListNode* h1, ListNode* h2){
        ListNode* res=new ListNode(-1);
        ListNode* cur=res;
        while(h1&&h2){
            if(h1->val>h2->val){
                cur->next=h2;
                h2=h2->next;
            }
            else{
                cur->next=h1;
                h1=h1->next;
            }
            cur=cur->next;
        }
        if(h1)cur->next=h1;
        if(h2)cur->next=h2;
        return res->next;
    }
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* f=head;
        ListNode* s=head;
        ListNode* spost=head;
        while(f&&f->next){
            f=f->next->next;
            spost=s;
            s=s->next;
        }
        
        spost->next=NULL;
        ListNode* lhs=sortList(head);
        ListNode* rhs=sortList(s);
        return Merge(rhs,lhs);
    }
};
