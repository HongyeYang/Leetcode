class Solution {
public:
    bool DST(TreeNode* root, long maxnum, long minnum){
        if(!root)return true;
        if(root->val>=maxnum||root->val<=minnum)return false;
        return DST(root->left,root->val,minnum)&&DST(root->right,maxnum,root->val);
        
    }
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        return DST(root,LONG_MAX,LONG_MIN);
    }
};
