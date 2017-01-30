class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(!root)return s;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* cur=q.front();
            q.pop();
            if(cur){
                s+=to_string(cur->val);
                s+=",";
                q.push(cur->left);
                q.push(cur->right);
            }
            else{
                s+="n,";
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        int i=0;
        while(data[i]!=',')i++;
        TreeNode* root=new TreeNode(stoi(data.substr(0,i)));
        queue<TreeNode*>q;
        q.push(root);
        i++;
        for(;i<data.size();i++){
            TreeNode* rt=q.front();
            q.pop();
            int start = i;
            while(data[i]!=',')i++;
            if(data.substr(start,i-start)!="n"){
                rt->left=new TreeNode(stoi(data.substr(start,i-start)));
            }
            i++;
            start=i;
            while(data[i]!=',')i++;
            if(data.substr(start,i-start)!="n"){
                rt->right=new TreeNode(stoi(data.substr(start,i-start)));
            }
            if(rt->left)q.push(rt->left);
            if(rt->right)q.push(rt->right);
        }
        return root;
    }
};
