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
    void inorder(TreeNode* root, vector<int>&mode, int &mfq,int &precursor,int &cur){
        if(!root)return;
        inorder(root->left,mode,mfq,precursor,cur);
        if(root->val==precursor)cur++;
        else{
            cur=1;
            precursor=root->val;
        }
        if(cur>mfq){
            mode.clear();
            mode.push_back(root->val);
            mfq=cur;
        }
        else if(cur==mfq)mode.push_back(root->val);
        inorder(root->right,mode,mfq,precursor,cur);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>mode;
        int mfq=0,precursor=INT_MIN,cur=0;
        inorder(root,mode,mfq,precursor,cur);
        return mode;
    }
};
