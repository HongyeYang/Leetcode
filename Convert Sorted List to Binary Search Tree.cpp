class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)return NULL;
        if(!head->next)return new TreeNode(head->val);
        ListNode* pre=head;
        ListNode* cur=head;
        ListNode* post=head;
        while(pre&&pre->next){
            pre=pre->next->next;
            post=cur;
            cur=cur->next;
        }
        TreeNode* root=new TreeNode(cur->val);
        post->next=NULL;
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(cur->next);
        return root;
    }
};
