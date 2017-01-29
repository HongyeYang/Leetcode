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
    int DFS(TreeNode* root,int s, int &sum){
        if(!root)return 0;
        s+=root->val;
        return (s==sum)+DFS(root->left,s,sum)+DFS(root->right,s,sum);
    }
    int pathSum(TreeNode* root, int sum) {
        if(!root)return 0;
        return DFS(root,0,sum)+pathSum(root->left,sum)+pathSum(root->right,sum);
    }
};
