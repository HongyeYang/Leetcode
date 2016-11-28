class Solution {
public:
    int dep(TreeNode* root){
        if(!root)return 0;
        int ll=dep(root->left);
        if(ll==-1)return -1;
        int rr=dep(root->right);
        if(rr==-1)return -1;
        if(abs(ll-rr)>1)return -1;
        else return max(rr,ll)+1;
    }
    bool isBalanced(TreeNode* root) {
        if(!root)return true;
        return dep(root)<0? false:true;
    }
};
