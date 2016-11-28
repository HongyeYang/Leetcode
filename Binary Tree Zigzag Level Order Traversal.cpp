class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return{};
        vector<vector<int>>res;
        queue<TreeNode*>roc;
        roc.push(root);
        roc.push(NULL);
        bool flag=false;
        while(roc.size()>1){
            vector<int>cur;
            while(roc.front()){
                TreeNode* cc=roc.front();
                roc.pop();
                cur.push_back(cc->val);
                if(cc->left)roc.push(cc->left);
                if(cc->right)roc.push(cc->right);
            }
            roc.pop();
            if(flag)reverse(cur.begin(),cur.end());
            flag=!flag;
            res.push_back(cur);
            roc.push(NULL);
        }
        return res;

    
    }
};
