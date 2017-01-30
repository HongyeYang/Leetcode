class Solution {
public:
struct cmp{
    bool operator()(pair<int,char>p1,pair<int,char>p2){
        return p1.first<p2.first;
    }
};
    string frequencySort(string s) {
        vector<int>roc(256,0);
        for(char &c:s)roc[c]++;
        priority_queue<pair<int,char>,vector<pair<int,char>>,cmp>pq;
        for(int i=0;i<256;i++){
            if(roc[i])pq.push({roc[i],(char)i});
        }
        string res;
        while(!pq.empty()){
            pair<int,char>tep=pq.top();
            pq.pop();
            string st(tep.first,tep.second);
            res+=st;
        }
        return res;
    }
};
