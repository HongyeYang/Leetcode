class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if(!head||!head->next)return head;
        ListNode* leftstart=NULL;
        ListNode* leftend=NULL;
        ListNode* rightstart=NULL;
        ListNode* rightend=NULL;
        ListNode* cur=head;
        while(cur){
            if(cur->val<x){
                if(!leftstart){
                    leftstart=cur;
                    leftend=cur;
                    head=leftstart;
                }
                else{
                leftend->next=cur;
                leftend=cur;
                }
            }
            else{
                if(!rightstart){
                    rightstart=cur;
                    rightend=cur;
                }
                else{
                rightend->next=cur;
                rightend=cur;
                }
            }
            cur=cur->next;
        }
        if(leftend)leftend->next=rightstart;
        if(rightend)rightend->next=NULL;
        return head;
    }
};
