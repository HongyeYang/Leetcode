class Solution {
public:
    void traversal(TreeNode* root,vector<int>&res){
        if(!root)return;
        if(root->left)traversal(root->left,res);
        res.push_back(root->val);
        if(root->right)traversal(root->right,res);
        return;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if(!root)return res;
        traversal(root,res);
        return res;
    }
};
