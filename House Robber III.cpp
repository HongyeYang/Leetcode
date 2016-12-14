class Solution {
public:
    pair<int,int> DFS(TreeNode* root){
        if(!root)return {0,0};
        pair<int,int>lt=DFS(root->left);
        pair<int,int>rt=DFS(root->right);
        return{lt.second+rt.second,max(lt.second+rt.second,lt.first+rt.first+root->val)};
    }
    int rob(TreeNode* root) {
        if(!root)return 0;
        pair<int,int> res=DFS(root);
        return max(res.first,res.second);
    }
};
