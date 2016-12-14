class Solution {
public:
    void DFS(string cur,unordered_map<string,multiset<string>>&roc,vector<string>&res){
        while(!roc[cur].empty()){
            string nt=*roc[cur].begin();
            roc[cur].erase(roc[cur].begin());
            DFS(nt,roc,res);
        }
        res.push_back(cur);
        return;
    }
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        unordered_map<string,multiset<string>>roc;
        for(auto c:tickets){
            roc[c.first].insert(c.second);
        }
        vector<string>res;
        DFS("JFK",roc,res);
        return vector<string>(res.rbegin(),res.rend());
    }
};
