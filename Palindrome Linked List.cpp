class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)return true;
        ListNode* f=head;
        ListNode* s=head;
        while(f&&f->next){
            f=f->next->next;
            s=s->next;
        }
        ListNode* post=s;
        ListNode* cur=post->next;
        ListNode* pre;
       s->next=NULL;
        while(cur){
            pre=cur->next;
            cur->next=post;
            post=cur;
            cur=pre;
        }
        
        cur=post;
        post=head;
        while(cur!=post){
            if(cur->val!=post->val)return false;
            cur=cur->next;
            post=post->next;
            if(!cur||post->next==cur)break;
        }
        if(cur&&cur->val!=post->val)return false;
        return true;
    }
};
