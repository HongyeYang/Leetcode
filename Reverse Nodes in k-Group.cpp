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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return head;
        ListNode* prehead=new ListNode(0);
        ListNode* cur=head;
        ListNode* pre=prehead;
        pre->next=cur;
        int kk=k-1;
        ListNode* start=cur;
        ListNode* end=cur;
        while(cur){
            start=cur;
            end=cur;
            //find the start and end , also to pre-check if there is a reverse to be done
            while(kk&&end){
                end=end->next;
                kk--;
            }
            if(kk||!end)break;
            ListNode* post=cur->next;
            kk=k-1;
            while(kk&&post){
                ListNode* ppost=post->next;
                post->next=cur;
                cur=post;
                post=ppost;
                kk--;
            }
            
            kk=k-1;
            pre->next=end;
            start->next=post;
            pre=start;
            cur=post;
        }
        if(kk&&cur)pre->next=start;
        return prehead->next;
    }
};
