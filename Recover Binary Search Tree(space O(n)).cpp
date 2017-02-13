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
    void inorder(TreeNode* root,vector<int>&valVec,vector<TreeNode*>&nodeVec){
        if(!root)return;
        inorder(root->left,valVec,nodeVec);
        valVec.push_back(root->val);
        nodeVec.push_back(root);
        inorder(root->right,valVec,nodeVec);
        return;
    }
    void recoverTree(TreeNode* root) {
        vector<int>valVec;
        vector<TreeNode*>nodeVec;
        inorder(root,valVec,nodeVec);
        sort(valVec.begin(),valVec.end());
        for(int i=0;i<valVec.size();i++)nodeVec[i]->val=valVec[i];
        return;
    }
};
