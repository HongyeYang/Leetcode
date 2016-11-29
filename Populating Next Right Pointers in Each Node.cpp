class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)return;
        queue<TreeLinkNode*>roc;
        roc.push(root);
        roc.push(NULL);
        while(roc.size()>1){
            TreeLinkNode* cur=NULL;
            TreeLinkNode* pre=NULL;
            while(roc.front()){
                if(cur)pre=cur;
                cur=roc.front();
                roc.pop();
                if(pre)pre->next=cur;
                if(cur->left)roc.push(cur->left);
                if(cur->right)roc.push(cur->right);
            }
            roc.pop();
            cur->next=NULL;
            roc.push(NULL);
        }
        return;
    }
};
