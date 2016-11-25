class Solution {
public:
    string step(string cur){
        int len=cur.size();
        int num=1;
        string res;
        for(int i=1;i<len;i++){
            if(cur[i]==cur[i-1])num++;
            else{
                res+=to_string(num);
                res.push_back(cur[i-1]);
                num=1;
            }
        }
        res+=to_string(num);
        res.push_back(cur[len-1]);
        return res;
    }
    string countAndSay(int n) {
        if(!n)return {};
        string cur="1";
        for(int i=1;i<n;i++){
            cur=step(cur);
        }
        return cur;
    }
};
