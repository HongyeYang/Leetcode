class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        unordered_map<char,char>mp={{'0','0'},{'1','1'},{'6','9'},{'8','8'},{'9','6'}};
        int lowlen=low.size(),highlen=high.size();
        string cur(lowlen-1,'0');
        int res=0;
        for(int len=lowlen;len<=highlen;len++){
            cur.push_back('0');
            dfs(low,high,cur,0,len-1,mp,res);
        }
        return res;
    }
    void dfs(string &low, string&high, string &cur,int left,int right, unordered_map<char,char>&mp,int &res ){
        if(left>right){
            if(((int)cur.size()==(int)low.size()&&cur.compare(low)<0)||((int)cur.size()==(int)high.size()&&cur.compare(high)>0))return;
            res++;
            return;
        }
        for(pair<char,char>p:mp){
            cur[left]=p.first;
            cur[right]=p.second;
            if((int)cur.size()>1&&cur[0]=='0')continue;
            if(left<right||(left==right&&p.first==p.second))dfs(low,high,cur,left+1,right-1,mp,res);
            cur[left]='0';
            cur[right]='0';
        }
        return;
    }
};
