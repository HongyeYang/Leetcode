class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)return {};
        vector<int>res;
        stack<TreeNode*>roc;
        roc.push(root);
        while(!roc.empty()){
            TreeNode* cur=roc.top();
            roc.pop();
            res.push_back(cur->val);
            if(cur->right)roc.push(cur->right);
            if(cur->left)roc.push(cur->left);
        }
        return res;
    }
};
