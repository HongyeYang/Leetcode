class Solution {
public:
    TreeNode* DST(TreeNode* root, int b, int s){
        if(!root||(root->val>=s&&root->val<=b))return root;
        TreeNode* lt=DST(root->left,b,s);
        return lt?lt:DST(root->right,b,s);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)return root;
        int b=max(p->val,q->val);
        int s=min(p->val,q->val);
        return DST(root,b,s);
    }
};
