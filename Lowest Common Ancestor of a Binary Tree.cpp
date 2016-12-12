class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root||root==p||root==q)return root;
        TreeNode* lt=lowestCommonAncestor(root->left,p,q);
        if(lt&&lt!=q&&lt!=p)return lt;
        TreeNode* rt=lowestCommonAncestor(root->right,p,q);
        if(lt&&rt)return root;
        if(lt)return lt;
        if(rt)return rt;
        return NULL;
    }
};
