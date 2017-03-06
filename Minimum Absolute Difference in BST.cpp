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
    int getMinimumDifference(TreeNode* root) {
        if(!root)return 0;
        stack<TreeNode*>st;
        TreeNode* cur=root;
        while(cur){
            st.push(cur);
            cur=cur->left;
        }
        int res=INT_MAX;
        int pre=INT_MAX-1;
        while(!st.empty()){
            cur=st.top();
            st.pop();
            res=min(res,abs(pre-cur->val));
            pre=cur->val;
            if(cur->right){
                cur=cur->right;
                while(cur){
                    st.push(cur);
                    cur=cur->left;
                }
            }
            
        }
        return res;
    }
};
