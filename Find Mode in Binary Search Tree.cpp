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
    void recur(TreeNode* root, unordered_map<int,int>&roc){
        if(!root)return;
        roc[root->val]++;
        recur(root->left,roc);
        recur(root->right,roc);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int>roc;
        recur(root,roc);
        
        vector<int>res;
        unordered_map<int,int>::iterator it;
        it=roc.begin();
        int target=0;
        for(;it!=roc.end();it++){
            target=max(target,it->second);
        }
        it=roc.begin();
        for(;it!=roc.end();it++){
            if(target==it->second)res.push_back(it->first);
        }
        return res;
    }
};
