class Solution {
public:
    void dfs(string &num, string&cur,long long curnum,long long diff,int start,vector<string>&res,int &target){
        if(start==num.size()){
            if(curnum==target)res.push_back(cur);
            return;
        }
        for(int i=start;i<num.size();i++){
            string cnum=num.substr(start,i-start+1);
            if(cnum[0]=='0'&&cnum.size()>1)return;
            long long cn=stoll(cnum);
            int oldsize=cur.size();
            //+
            cur+=("+"+cnum);
            dfs(num,cur,curnum+cn,cn,i+1,res,target);
            //-
            cur=cur.substr(0,oldsize)+"-"+cnum;
            dfs(num,cur,curnum-cn,-cn,i+1,res,target);
            
            //*
            cur=cur.substr(0,oldsize)+"*"+cnum;
            dfs(num,cur,curnum+(diff*(cn-1)),diff*cn,i+1,res,target);
            
            cur=cur.substr(0,oldsize);
        }
        return;
    }
    vector<string> addOperators(string num, int target) {
        string cur;
        vector<string>res;
        for(int i=0;i<num.size();i++){
            cur=num.substr(0,i+1);
            if(cur[0]=='0'&&cur.size()>1)break;
            dfs(num,cur,stoll(cur),stoll(cur),i+1,res,target);
        }
        return res;
    }
};
