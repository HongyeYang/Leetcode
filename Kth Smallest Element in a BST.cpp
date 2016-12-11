class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>roc;
        TreeNode* cur=root;
        while(cur){
            roc.push(cur);
            cur=cur->left;
        }
        while(k){
            cur=roc.top();
            roc.pop();
            k--;
            if(!k)return cur->val;
            cur=cur->right;
            while(cur){
                roc.push(cur);
                cur=cur->left;
            }
        }
        return cur->val;
    }
};
