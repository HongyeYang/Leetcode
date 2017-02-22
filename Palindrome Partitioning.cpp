class Solution {
public:
    bool isPan(string s){
        string r=s;
        reverse(s.begin(),s.end());
        return s==r;
    }
    vector<vector<string>> partition(string s) {
        int len=s.size();
        if(len<2)return {{s}};
        vector<vector<int>>isP(len,vector<int>(len,0));
        for(int i=0;i<len;i++)isP[i][i]=1;
        vector<vector<string>>res;
        vector<string>cur;
        dfs(s,0,res,isP,cur);
        return res;
    }
    void dfs(string s, int start, vector<vector<string>>&res, vector<vector<int>>&isP, vector<string>&cur){
        if(start>=s.size()){
            res.push_back(cur);
            return;
        }
        for(int i=start;i<s.size();i++){
            if(isP[start][i]==0){
                if(isPan(s.substr(start,i-start+1)))isP[start][i]=1;
                else isP[start][i]=-1;
            }
            if(isP[start][i]==1){
                cur.push_back(s.substr(start,i-start+1));
                dfs(s,i+1,res,isP,cur);
                cur.pop_back();
            }
        }
        return;
    }
};
