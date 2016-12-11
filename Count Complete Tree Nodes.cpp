class Solution {
public:
    int countNodes(TreeNode* root) {
       if(!root)return 0;
       TreeNode* p=root;
       int hl=0,hr=0;
       while(p){
           p=p->left;
           hl++;
       }
       p=root;
       while(p){
           p=p->right;
           hr++;
       }
       if(hr==hl)return pow(2,hl)-1;
       return 1+countNodes(root->left)+countNodes(root->right);
    }
};
