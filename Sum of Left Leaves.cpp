class Solution {
public:
    void DSF(TreeNode* root,int& res,bool lt){
        if((!root->left)&&(!root->right)&&lt){
            res+=root->val;
            return;
        }
        if(root->left)DSF(root->left,res,true);
        if(root->right)DSF(root->right,res,false);
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int res=0;
        if(!root)return 0;
        DSF(root,res,false);
        return res;
    }
};
