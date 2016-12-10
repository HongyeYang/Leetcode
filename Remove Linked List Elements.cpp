class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head&&head->val==val)head=head->next;
        if(!head)return head;
        ListNode* pre=head->next;
        ListNode* cur=head;
        ListNode* post=head;
        while(cur){
            pre=cur->next;
            if(cur->val==val)post->next=pre;
            else post=cur;
            cur=pre;
        }
        return head;
    }
};
