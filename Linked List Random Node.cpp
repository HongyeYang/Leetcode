class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    ListNode* h;
    Solution(ListNode* head) {
        h=head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int cnt=1,res=h->val;
        ListNode* cur=h;
        while(cur){
            if(rand()%cnt==0)res=cur->val;
            cnt++;
            cur=cur->next;
        }
        return res;
    }
};
