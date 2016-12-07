class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* res=new ListNode(-1);
        ListNode* cur=res;
        while(head){
            ListNode* next=head->next;
            while(cur->next&&cur->next->val<head->val)cur=cur->next;
            head->next=cur->next;
            cur->next=head;
            head=next;
            cur=res;
        }
        return res->next;
    }
};
