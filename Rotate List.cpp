class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!k||!head)return head;
        ListNode* flag=head;
        int ii=0;
        while(k){
            flag=flag->next;
            k--;
            ii++;
            if(!flag)return rotateRight(head,k%ii);
        }
        ListNode* post=head;
        while(flag->next){
            flag=flag->next;
            post=post->next;
        }
        ListNode* tep=post->next;
        post->next=NULL;
        flag->next=head;
        head=tep;
        return head;
    }
};
