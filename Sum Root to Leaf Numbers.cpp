class Solution {
public:
    void DST(TreeNode* root,int cur,int &res){
        if(!root->left&&!root->right){
            res=res+cur*10+root->val;
            return;
        }
        cur=cur*10+root->val;
        if(root->left)DST(root->left,cur,res);
        if(root->right)DST(root->right,cur,res);
        return;
    }
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        int res=0;
        DST(root,0,res);
        return res;
    }
};
