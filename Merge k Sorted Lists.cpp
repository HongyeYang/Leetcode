class Solution {
public:
    struct cmp{
      bool operator()(ListNode* l1,ListNode* l2){
          return l1->val>l2->val;
      }  
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;
        for(auto c:lists)if(c)pq.push(c);
        ListNode* head=new ListNode(0);
        ListNode* cur=head;
        while(!pq.empty()){
            ListNode* node=pq.top();
            pq.pop();
            cur->next=node;
            cur=cur->next;
            if(node->next)pq.push(node->next);
        }
        cur->next=NULL;
        return head->next;
    }
};
