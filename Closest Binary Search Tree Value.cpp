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
    int closestValue(TreeNode* root, double target) {
        if(target==root->val)return root->val;
        else if(target<root->val){
            if(!root->left)return root->val;
            int lt=closestValue(root->left,target);
            if(abs(lt-target)<abs(root->val-target))return lt;
        }
        else{
            if(!root->right)return root->val;
            int rt=closestValue(root->right,target);
            if(abs(rt-target)<abs(root->val-target))return rt;
        }
        return root->val;
    }
};
