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
    vector<vector<int>> findLeaves(TreeNode* root) {
        if(!root)return {};
        vector<vector<int>>res;
        int dep=dfs(root,res);
        return res;
    }
    
    int dfs(TreeNode* root, vector<vector<int>>&res){
        int dep=1;
        if(root->left)dep=max(dep,dfs(root->left,res)+1);
        if(root->right)dep=max(dep,dfs(root->right,res)+1);
        if(res.size()<dep){
            res.push_back({root->val});
        }
        else res[dep-1].push_back(root->val);
        return dep;
    }
};
