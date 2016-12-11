class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        TreeNode* tep=root->left;
        root->left=invertTree(root->right);
        root->right=invertTree(tep);
        return root;
    }
};
