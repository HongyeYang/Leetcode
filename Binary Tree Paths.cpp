class Solution {
public:
    void DST(TreeNode* root, string cur,vector<string>&res){
        if((!root->left)&&(!root->right)){
            res.push_back(cur);
        }
        string tep=cur;
        if(root->left){
            tep+="->";
            tep+=to_string(root->left->val);
            DST(root->left,tep,res);
        }
        if(root->right){
            cur+="->";
            cur+=to_string(root->right->val);
            DST(root->right,cur,res);
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)return {};
        vector<string>res;
        string cur;
        cur+=to_string(root->val);
        DST(root,cur,res);
        return res;
    }
};
