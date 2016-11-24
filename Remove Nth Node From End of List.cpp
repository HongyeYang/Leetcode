class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* pre=head;
        while(n){
            pre=pre->next;
            n--;
        }
        if(!pre){
            head=head->next;
            return head;
        }
        ListNode* cur=head;
        ListNode* post=head;
        while(pre){
            pre=pre->next;
            post=cur;
            cur=cur->next;
        }
        cur=cur->next;
        post->next=cur;
        return head;
    }
};
