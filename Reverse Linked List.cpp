class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* cur=head->next;
        ListNode* pre=head;
        ListNode* post=head;
        head->next=NULL;
        while(cur){
            pre=cur->next;
            cur->next=post;
            post=cur;
            cur=pre;
        }
        return post;
    }
};
