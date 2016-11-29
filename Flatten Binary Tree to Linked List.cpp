class Solution {
public:
    pair<TreeNode*, TreeNode*>DST(TreeNode* root){
        if(!root->left&&!root->right)return {root,root};
        pair<TreeNode*,TreeNode*>res;
        res.first=root;
        if(!root->left){
            pair<TreeNode*,TreeNode*>tep=DST(root->right);
            res.second=tep.second;
        }
        else if(!root->right){
            pair<TreeNode*,TreeNode*>tep=DST(root->left);
            root->left=NULL;
            root->right=tep.first;
            res.second=tep.second;
        }
        else{
            pair<TreeNode*,TreeNode*>tep1=DST(root->left);
            pair<TreeNode*,TreeNode*>tep2=DST(root->right);
            root->left=NULL;
            root->right=tep1.first;
            tep1.second->right=tep2.first;
            res.second=tep2.second;
        }
        return res;
        
    }
    void flatten(TreeNode* root) {
        if(!root)return;
        pair<TreeNode*,TreeNode*>Subtree=DST(root);
        return;
       
    }
};
