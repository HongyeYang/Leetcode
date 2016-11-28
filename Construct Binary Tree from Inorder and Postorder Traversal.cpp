class Solution {
public:
    TreeNode* recur(vector<int>& inorder,vector<int>& postorder, int start_in, int end_in,int start_post, int end_post){
        if(start_in>end_in)return NULL;
        TreeNode* root=new TreeNode(postorder[end_post]);
        int i=start_in;
        for(;i<=end_in;i++){
            if(inorder[i]==root->val){
                break;
            }
        }
        root->left=recur(inorder,postorder,start_in,i-1,start_post,start_post+i-start_in-1);
        root->right=recur(inorder,postorder,i+1,end_in,start_post+i-start_in,end_post-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len=inorder.size();
        if(!len)return NULL;
        return recur(inorder,postorder,0,len-1,0,len-1);
    }
};
