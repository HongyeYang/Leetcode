class BSTIterator {
private:
stack<TreeNode*>roc;
public:
    BSTIterator(TreeNode *root) {
        intoRoc(root);
    }
    void intoRoc(TreeNode* root){
        while(root){
            roc.push(root);
            root=root->left;
        }
        return;
    }
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !roc.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* cur=roc.top();
        int res=cur->val;
        roc.pop();
        if(cur->right)intoRoc(cur->right);
        return res;
    }
};
