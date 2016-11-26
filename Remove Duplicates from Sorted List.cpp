class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* cur=head->next;
        ListNode* border=head;
        while(cur){
            if(cur->val==border->val)cur=cur->next;
            else{
                border->next=cur;
                border=cur;
                cur=cur->next;
            }
        }
        border->next=NULL;
        return head;
    }
};
