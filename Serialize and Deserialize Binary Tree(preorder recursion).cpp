/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void dfs_serial(TreeNode* root,string &s){
        if(!root)s+="n,";
        else{
            s+=(to_string(root->val)+",");
            dfs_serial(root->left,s);
            dfs_serial(root->right,s);
        }
        return;
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        dfs_serial(root,s);
        return s;
    }
    
    TreeNode* dfs_deserial(string &data,int &start){
        if(data[start]=='n'){
            start+=2;
            return NULL;
        }
        else{
            int i=start;
            while(data[start]!=',')start++;
            TreeNode* root=new TreeNode(stoi(data.substr(i,start-i)));
            start++;
            root->left=dfs_deserial(data,start);
            root->right=dfs_deserial(data,start);
            return root;
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int start=0;
        return dfs_deserial(data,start);
    }
};
