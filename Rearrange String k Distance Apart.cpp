class Solution {
public:
    string rearrangeString(string s, int k) {
        if(k<2)return s;
        vector<int>roc(26,0);
        for(char c:s)roc[c-'a']++;
        int len=s.size();
        priority_queue<pair<int,char>>pq;
        for(int i=0;i<26;i++){
            if(roc[i]){
                pq.push({roc[i],'a'+i});
            }
        }
        string res;
        while(!pq.empty()){
            vector<pair<int,int>>tep;
            int cnt=min(k,len);
            for(int i=0;i<cnt;i++){
                if(pq.empty())return "";
                auto cur=pq.top();
                pq.pop();
                res.push_back(cur.second);
                len--;
                cur.first--;
                if(cur.first>0)tep.push_back(cur);
            }
            for(auto &p:tep)pq.push(p);
        }
        return res;
    }
};
