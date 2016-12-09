class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>roc;
        vector<int>res;
        roc.push(root);
        roc.push(NULL);
        while(roc.size()>1){
            TreeNode* cur=roc.front();
            roc.pop();
            res.push_back(cur->val);
            if(cur->right)roc.push(cur->right);
            if(cur->left)roc.push(cur->left);
            while(roc.front()){
                cur=roc.front();
                roc.pop();
                if(cur->right)roc.push(cur->right);
                if(cur->left)roc.push(cur->left);
            }
            roc.pop();
            roc.push(NULL);
        }
        return res;
    }
};
