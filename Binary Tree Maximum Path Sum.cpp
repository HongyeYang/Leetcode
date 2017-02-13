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
    int inorder(TreeNode* root,int &res){
        if(!root)return INT_MIN;
        int l=inorder(root->left,res);
        int r=inorder(root->right,res);
        int cur=root->val;
        cur+=max(0,max(r,l));
        res=max(res,cur);
        if(l>0&&r>0)res=max(res,l+r+root->val);
        return cur;
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        int k=inorder(root,res);
        return res;
    }
};
