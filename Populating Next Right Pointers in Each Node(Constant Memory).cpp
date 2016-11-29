class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)return;
        TreeLinkNode* nextleft=root->left;
        TreeLinkNode* cur=root;
        while(nextleft){
            while(cur){
                cur->left->next=cur->right;
                if(cur->next)cur->right->next=cur->next->left;
                cur=cur->next;
            }
            cur=nextleft;
            nextleft=nextleft->left;
        }
        return;
    }
};
