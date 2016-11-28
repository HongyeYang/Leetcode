class Solution {
public:
    void DST(TreeNode* root,int sum, vector<int>&cur, vector<vector<int>>&res){
        if(!root->left&&!root->right&&!sum){
            res.push_back(cur);
            return;
        }
        if(root->left){
            cur.push_back(root->left->val);
            DST(root->left,sum-root->left->val,cur,res);
            cur.pop_back();
        }
        if(root->right){
            cur.push_back(root->right->val);
            DST(root->right,sum-root->right->val,cur,res);
            cur.pop_back();
        }
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(!root)return {};
        vector<vector<int>>res;
        vector<int>cur;
        cur.push_back(root->val);
        DST(root,sum-root->val,cur,res);
        return res;
    }
};
