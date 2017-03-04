/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if(!head)return head;
        //two pass
        ListNode* pre=head->next;
        ListNode* cur=head;
    
        //forward
        cur->next=NULL;
        while(pre){
            ListNode*tep=pre->next;
            pre->next=cur;
            cur=pre;
            pre=tep;
        }
        //backward
        int d=1;
        
        
        pre=cur->next;
        cur->next=NULL;
        while(pre){
            cur->val+=d;
            d=0;
            if(cur->val>=10){
                d=1;
                cur->val-=10;
            }
            ListNode* tep=pre->next;
            pre->next=cur;
            cur=pre;
            pre=tep;
        }
        cur->val+=d;
        d=0;
        if(cur->val>=10){
            d=1;
            cur->val-=10;
        }
        if(d){
            head=new ListNode(d);
            head->next=cur;
        }
        return head;
    
    }
};
