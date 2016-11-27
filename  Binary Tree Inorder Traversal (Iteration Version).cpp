class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if(!root)return res;
        stack<TreeNode*>roc;
        TreeNode* cur=root;
        while(cur||!roc.empty()){
            while(cur){
                roc.push(cur);
                cur=cur->left;
            }
            cur=roc.top();
            roc.pop();
            res.push_back(cur->val);
            cur=cur->right;
        }
        return res;
    }
};
