class Solution {
public:
    vector<TreeNode*> recursion(int start, int end){
        vector<TreeNode*>res;
        if(start>end){
            res.push_back(NULL);
            return res;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*>leftSubtrees=recursion(start,i-1);
            vector<TreeNode*>rightSubtrees=recursion(i+1,end);
            for(int j=0;j<leftSubtrees.size();j++){
                for(int k=0;k<rightSubtrees.size();k++){
                    TreeNode* node=new TreeNode(i);
                    node->left=leftSubtrees[j];
                    node->right=rightSubtrees[k];
                    res.push_back(node);
                }
            }
            
        }
        return res;
    }
    vector<TreeNode*> generateTrees(int n) {
        if(!n)return{};
        return recursion(1,n);
    }
};
