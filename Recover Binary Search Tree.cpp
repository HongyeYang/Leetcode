/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,TreeNode*& pre,TreeNode* &first,TreeNode* &second){
        if(!root)return;
        inorder(root->left,pre,first,second);
        if(pre&&pre->val>root->val){
            if(!first)first=pre;
            second=root;
        }
        pre=root;
        inorder(root->right,pre,first,second);
        return;
    }
    void recoverTree(TreeNode* root) {
        TreeNode* pre=NULL;
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        inorder(root,pre,first,second);
        if(first&&second)swap(first->val,second->val);
        return;
    }
};
