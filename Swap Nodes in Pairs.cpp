class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* pre=head->next;
        ListNode* post=head;
        while(pre){
            swap(pre->val,post->val);
            if(!pre->next||!pre->next->next)break;
            pre=pre->next->next;
            post=post->next->next;
        }
        return head;
    }
};
