class Solution {
public:
    TreeNode* recur(vector<int>& preorder,vector<int>& inorder,int start_pre, int end_pre,int start_in, int end_in){
        if(start_pre>end_pre)return NULL;
        int border=0;
        TreeNode* root=new TreeNode(preorder[start_pre]);
        for(int i=start_in;i<=end_in;i++){
            if(inorder[i]==preorder[start_pre]){
                border=i;
                break;
            }
        }
        root->left=recur(preorder,inorder,start_pre+1,border-start_in+start_pre,start_in,border-1);
        root->right=recur(preorder,inorder,border-start_in+start_pre+1,end_pre,border+1,end_in);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size())return NULL;
        return recur(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
};
