class Solution {
public:
    void BST(vector<int>&cur,vector<bool>&roc,vector<vector<int>>&res,int n,int k){
        if(!k){
            res.push_back(cur);
            return;
        }
        int start=0;
        if(cur.size())start=cur.back();
        for(int i=start;i<n-k+1;i++){
            if(roc[i]){
                cur.push_back(i+1);
                roc[i]=false;
                BST(cur,roc,res,n,k-1);
                cur.pop_back();
                roc[i]=true;
            }
        }
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        if(!n||!k||k>n)return{};
        vector<vector<int>>res;
        vector<int>cur;
        vector<bool>roc(n,true);
        BST(cur,roc,res,n,k);
        return res;
    }
};
