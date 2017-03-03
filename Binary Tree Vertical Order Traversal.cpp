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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root)return {};
        map<int,vector<int>>roc;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto &p=q.front();
            q.pop();
            roc[p.second].push_back(p.first->val);
            if(p.first->left){
                q.push({p.first->left,p.second-1});
            }
            if(p.first->right){
                q.push({p.first->right,p.second+1});
            }
        }
        
        vector<vector<int>>res;
        auto it= roc.begin();
        for(;it!=roc.end();it++){
            res.push_back(it->second);
        }
        return res;
    }
};
