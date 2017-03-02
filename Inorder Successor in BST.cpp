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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p->right){
            TreeNode* cur=p->right;
            while(cur->left)cur=cur->left;
            return cur;
        }
        else{
            TreeNode* res=NULL;
            while(root!=p){
                if(root->val<p->val){
                    root=root->right;
                }
                else{
                    res=root;
                    root=root->left;
                }
            }
            return res;
        }
    }
};
