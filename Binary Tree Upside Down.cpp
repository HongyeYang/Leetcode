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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root)return root;
        //pair<original_root,currentRoot>
        pair<TreeNode*, TreeNode*>p=dfs(root);
        return p.second;
    }
    pair<TreeNode*, TreeNode*> dfs(TreeNode* root){
        if(!root||!root->left)return {root,root};
        pair<TreeNode*,TreeNode*>lt=dfs(root->left);
        pair<TreeNode*,TreeNode*>rt=dfs(root->right);
        root->left=NULL;
        root->right=NULL;
        lt.first->left=rt.first;
        lt.first->right=root;
        return {root,lt.second};
    }
};
