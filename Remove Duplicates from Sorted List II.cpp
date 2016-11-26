class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)return head;
        
        if(head->val==head->next->val){
            ListNode* cur=head->next->next;
            ListNode* post=head->next;
            while(cur&&((cur->val==post->val)||(cur->next&&cur->next->val==cur->val))){
                post=cur;
                cur=cur->next;
            }
            head=cur;
            if(!head||!head->next)return head;
        }
        ListNode* border=head;
        ListNode* cur=head->next;
        ListNode* post=head;
        while(cur->next){
            if(cur->next->val!=cur->val&&cur->val!=post->val){
                border->next=cur;
                border=cur;
                post=cur;
                cur=cur->next;
            }
            else{
                post=cur;
                cur=cur->next;
            }
        }
        if(cur->val!=post->val){
            border->next=cur;
            border=cur;
        }
        border->next=NULL;
        return head;
    }
};
