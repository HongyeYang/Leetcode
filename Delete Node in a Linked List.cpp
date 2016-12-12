class Solution {
public:
    void deleteNode(ListNode* node) {
        if(!node->next){
            node=NULL;
        }
        else{
            node->val=node->next->val;
            node->next=node->next->next;
        }
        return;
    }
};
