class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* lt=NULL;
        TreeLinkNode* pre=NULL;
        TreeLinkNode* parent=root;
        while(parent){
            if(parent->left){
                if(pre){
                    pre->next=parent->left;
                    pre=pre->next;
                }
                else {
                    pre=parent->left;
                    lt=parent->left;
                }
            }
            if(parent->right){
                if(pre){
                    pre->next=parent->right;
                    pre=pre->next;
                }
                else{
                   pre=parent->right;
                   lt=parent->right;
                } 
            }
            if(parent->next)parent=parent->next;
            else{
                parent=lt;
                lt=NULL;
                pre=NULL;
            }
        }
        return ;
    }
};
