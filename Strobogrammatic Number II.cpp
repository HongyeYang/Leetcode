class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        if(n==1)return {"0","1","8"};
        string num="01869";
        //first half;
        vector<string>res;
        string cur;
        int i=0;
        if(n>1)i=1;
        for(;i<5;i++){
            cur.push_back(num[i]);
            dfs(num,cur,res,n/2-1,n);
            cur.pop_back();
        }
        
        //second half
        unordered_map<char,char>m;
        m['0']='0';
        m['1']='1';
        m['6']='9';
        m['8']='8';
        m['9']='6';

        for(int i=0;i<res.size();i++){
            for(int j=n/2-1;j>=0;j--){
                res[i].push_back(m[res[i][j]]);
            }
        }
        return res;
    }
    void dfs(string &num,string &cur,vector<string>&res,int cnt,int & n){
        if(cnt==0){
            if(n&1){
                for(int i=0;i<3;i++){
                    cur.push_back(num[i]);
                    res.push_back(cur);
                    cur.pop_back();
                }
            }
            else res.push_back(cur);
            return;
        }
        for(int i=0;i<5;i++){
            cur.push_back(num[i]);
            dfs(num,cur,res,cnt-1,n);
            cur.pop_back();
        }
        return;
    }
};
