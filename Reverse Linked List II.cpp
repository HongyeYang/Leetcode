class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head||m==n)return head;
        bool flag=false;
        if(m==1)flag=true;
        ListNode* restart;
        ListNode* restart_pre;
        ListNode* cur=head;
        ListNode* pre=head;
        while(m>1){
            pre=cur;
            cur=cur->next;
            m--;
            n--;
        }
        restart=cur;
        restart_pre=pre;
        ListNode* post=cur->next;
        while(n>1){
            pre=cur;
            cur=post;
            post=cur->next;
            cur->next=pre;
            n--;
        }

        restart_pre->next=cur;
        restart->next=post;
        if(flag)head=cur;
        return head;
    }
};
