class Solution {
public:
    int DST(TreeNode* root,int dep){
        if(!root)return dep;
        return max(DST(root->left,dep+1),DST(root->right,dep+1));
    }
    int maxDepth(TreeNode* root) {
        if(!root)return 0;
        return DST(root,0);
    }
};
