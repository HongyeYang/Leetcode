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
    int largestBSTSubtree(TreeNode* root) {
        if(!root)return 0;
        int cur=0;
        int res=1;
        vector<int> p=dfs(root,res);
        return res;
    }
    vector<int>dfs(TreeNode* root,int &res){
        vector<int>r(4,0);
        r[0]=root->val;
        r[1]=root->val;
        r[2]=1;
        vector<int>lt;
        vector<int>rt;
        if(root->left)lt=dfs(root->left,res);
        if(root->right)rt=dfs(root->right,res);
        if(lt.size()){
            if(lt[3]==1)return lt;
            if(lt[1]<root->val){
                r[2]+=lt[2];
                r[0]=lt[0];
            }
            else return {0,0,0,1};
        }
        if(rt.size()){
            if(rt[3]==1)return rt;
            if(rt[0]>root->val){
                r[2]+=rt[2];
                r[1]=rt[1];
            }
            else return {0,0,0,1};
        }    
        res=max(r[2],res);
        return r;
    }
};
