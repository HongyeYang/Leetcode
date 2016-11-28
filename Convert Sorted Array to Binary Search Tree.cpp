class Solution {
public:
    TreeNode* generation(vector<int>& nums,int start,int end){
        if(end<start)return NULL;
        int mid=(start+end+1)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=generation(nums,start,mid-1);
        root->right=generation(nums,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len=nums.size();
        if(!len)return NULL;
        return generation(nums,0,len-1);
    }
};
