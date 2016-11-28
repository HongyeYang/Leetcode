class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root||(!root->left&&!root->right))return true;
        stack<TreeNode*>l,r;
        l.push(root->left);
        r.push(root->right);
        while(!l.empty()){
            TreeNode* ll=l.top();
            l.pop();
            TreeNode* rr=r.top();
            r.pop();
            if(!ll&&!rr)continue;
            if((!ll&&rr)||(ll&&!rr)||(ll->val!=rr->val))return false;
            l.push(ll->right);l.push(ll->left);
            r.push(rr->left);r.push(rr->right);
        }
        return true;
    }
};
