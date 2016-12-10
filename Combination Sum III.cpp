class Solution {
public:
    void recur(int k, int n,int start,vector<vector<int>>&res,vector<int>&cur,vector<bool>&roc){
        if(!k){
            if(!n)res.push_back(cur);
            return;
        }
        for(int i=start;i<11-k;i++){
            if(roc[i]){
                cur.push_back(i);
                roc[i]=false;
                recur(k-1,n-i,i+1,res,cur,roc);
                cur.pop_back();
                roc[i]=true;
            }
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>cur;
        vector<bool>roc(10,true);
        roc[0]=false;
        recur(k,n,0,res,cur,roc);
        return res;
    }
};
