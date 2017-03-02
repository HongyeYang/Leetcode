class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        stack<TreeNode*>s;
        TreeNode* cur=root;
        s.push(cur);
        while(cur->left){
            s.push(cur->left);
            cur=cur->left;
        }
        deque<int>inorder;
        
        while(!s.empty()){
            cur=s.top();
            s.pop();
            if(inorder.size()<k){
                inorder.push_back(cur->val);
            }
            else{
                if(abs(target-inorder.front())<abs(target-cur->val))break;
                else{
                    inorder.pop_front();
                    inorder.push_back(cur->val);
                }
            }
            
            if(cur->right){
                cur=cur->right;
                while(cur){
                    s.push(cur);
                    cur=cur->left;
                }
            }
        }
        return vector<int>(inorder.begin(),inorder.end());
    }
};
