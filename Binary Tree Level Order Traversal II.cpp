class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)return{};
        vector<vector<int>>res;
        queue<TreeNode*>roc;
        roc.push(root);
        roc.push(NULL);
        while(roc.size()>1){
            vector<int>cur;
            while(roc.front()){
                TreeNode* cc=roc.front();
                roc.pop();
                cur.push_back(cc->val);
                if(cc->left)roc.push(cc->left);
                if(cc->right)roc.push(cc->right);
            }
            roc.pop();
            res.push_back(cur);
            roc.push(NULL);
        }
        reverse(res.begin(),res.end());
        return res;

    }
};
