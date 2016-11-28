class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)return 0;
        queue<TreeNode*>roc;
        int res=0;
        roc.push(root);
        roc.push(NULL);
        while(roc.size()>1){
            res++;
            while(roc.front()){
                TreeNode* cur=roc.front();
                roc.pop();
                if(!cur->left&&!cur->right)return res;
                if(cur->left)roc.push(cur->left);
                if(cur->right)roc.push(cur->right);
            }
            roc.pop();
            roc.push(NULL);
        }
        return res;
    }
};
