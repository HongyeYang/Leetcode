class Solution {
public:
    bool checkstep(TreeNode* leftnode, TreeNode* rightnode){
        if(!leftnode&&!rightnode)return true;
        if((!leftnode&&rightnode)||(leftnode&&!rightnode)||leftnode->val!=rightnode->val)return false;
        return checkstep(leftnode->left,rightnode->right)&&checkstep(leftnode->right,rightnode->left);
        
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return true;
        return checkstep(root->left,root->right);
        
    }
};
