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
    vector<int> largestValues(TreeNode* root) {
        if(!root)return {};
        vector<int>res;
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int maxnum=root->val;
        while(!q.empty()){
            if(q.front()!=NULL){
                maxnum=max(q.front()->val,maxnum);
                if(q.front()->left)q.push(q.front()->left);
                if(q.front()->right)q.push(q.front()->right);
                q.pop();
            }
            else{
                q.pop();
                res.push_back(maxnum);
                if(!q.empty()){
                    maxnum=q.front()->val;
                    q.push(NULL);
                }
            }
        }
        return res;
    }
};
