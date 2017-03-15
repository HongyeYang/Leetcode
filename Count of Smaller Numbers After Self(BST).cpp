class Solution {
public:
    struct TreeNode{
        int val;
        int dup;
        int smallcnt;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int v,int s):val(v),dup(1),smallcnt(s),left(NULL),right(NULL){}
    };
    
    vector<int> countSmaller(vector<int>& nums) {
        int len=nums.size();
        vector<int>res(len,0);
        TreeNode* root=NULL;
        for(int i=len-1;i>=0;i--){
            root=insert(root,nums[i],0,res,i);
        }
        return res;
    }
    
    TreeNode* insert(TreeNode* root,int val,int presum,vector<int>&res,int &i){
        if(!root){
            root=new TreeNode(val,0);
            res[i]=presum;
        }
        else if(root->val==val){
            root->dup++;
            res[i]=root->smallcnt+presum;
        }
        else if(root->val>val){
            root->smallcnt++;
            root->left=insert(root->left,val,presum,res,i);
        }
        else{
            root->right=insert(root->right,val,presum+root->smallcnt+root->dup,res,i);
        }
        return root;
    }
};
