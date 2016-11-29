class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head||!head->next)return false;
        ListNode* pre=head;
        ListNode* post=head;
        while(pre&&pre->next){
            pre=pre->next->next;
            post=post->next;
            if(pre==post)return true;
        }
        return false;
    }
};
