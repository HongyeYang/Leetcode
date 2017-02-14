/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)return {};
        stack<TreeNode*>st;
        st.push(root);
        TreeNode* head=root;
        vector<int>res;
        while(!st.empty()){
            TreeNode* top=st.top();
            if(((!top->left)&&(!top->right))||top->left==head||top->right==head){
                res.push_back(top->val);
                st.pop();
                head=top;
            }
            else{
                if(top->right)st.push(top->right);
                if(top->left)st.push(top->left);
            }
        }
        return res;
    }
};
