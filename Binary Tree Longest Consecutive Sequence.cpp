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
    int longestConsecutive(TreeNode* root) {
        int res=0;
        int cur=dfs(root,res);
        return res;
    }
    int dfs(TreeNode* root, int &res){
        if(!root)return 0;
        int cur=1;
        if(root->left){
            int lt=dfs(root->left,res);
            if(root->left->val==root->val+1){
                cur=lt+1;
            }
        }
        if(root->right){
            int rt=dfs(root->right,res);
            if(root->right->val==root->val+1){
                cur=max(cur,rt+1);
            }
        }
        res=max(res,cur);
        return cur;
    }
};
