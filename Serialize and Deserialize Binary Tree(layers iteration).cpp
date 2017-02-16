class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        TreeNode* cur;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            cur=q.front();
            q.pop();
            if(!cur)s+="n,";
            else{
                s+=(to_string(cur->val)+",");
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0]=='n')return NULL;
        int i=0;
        while(data[i]!=',')i++;
        TreeNode* root=new TreeNode(stoi(data.substr(0,i++)));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(data[i]=='n')i+=2;
            else{
                int start=i;
                while(data[i]!=',')i++;
                cur->left=new TreeNode(stoi(data.substr(start,i-start)));
                i++;
                q.push(cur->left);
            }
            
            if(data[i]=='n')i+=2;
            else{
                int start=i;
                while(data[i]!=',')i++;
                cur->right=new TreeNode(stoi(data.substr(start,i-start)));
                i++;
                q.push(cur->right);
            }
        }
        return root;
    }
};
