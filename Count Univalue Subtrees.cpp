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
    int countUnivalSubtrees(TreeNode* root) {
        int res=0;
        bool r=dfs(root,res);
        return res;
    }
    bool dfs(TreeNode* root, int &res){
        if(!root)return true;
        bool l=dfs(root->left,res);
        bool r=dfs(root->right,res);
        if(l&&r){
            if(root->left&&root->left->val!=root->val)return false;
            if(root->right&&root->right->val!=root->val)return false;
            else{
                res++;
                return true;
            }
        }
        return false;
    }
};
