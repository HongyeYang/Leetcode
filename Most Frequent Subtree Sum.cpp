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
    int recur(TreeNode* root, unordered_map<int,int>&roc){
        if(!root)return 0;
        int rr=recur(root->left,roc)+recur(root->right,roc)+root->val;
        roc[rr]++;
        return rr;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>roc;
        int rr=recur(root,roc);
        unordered_map<int,int>::iterator it=roc.begin();
        int target=0;
        for(;it!=roc.end();it++){
            target=max(target,it->second);
        }
        it=roc.begin();
        vector<int>res;
        for(;it!=roc.end();it++){
            if(it->second==target)res.push_back(it->first);
        }
        return res;
    }
};
