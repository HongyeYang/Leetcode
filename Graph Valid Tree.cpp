class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<unordered_set<int>>path(n,unordered_set<int>{});
        //building path matrix
        for(pair<int,int>& p:edges){
            path[p.first].insert(p.second);
            path[p.second].insert(p.first);
        }
        unordered_set<int>passed;
        unordered_set<int>to_pass;
        to_pass.insert(0);
        while(!to_pass.empty()){
            int cur=*to_pass.begin();
            to_pass.erase(to_pass.begin());
            if(passed.count(cur))return false;
            passed.insert(cur);
            auto it=path[cur].begin();
            for(;it!=path[cur].end();it++){
                if(to_pass.count(*it))return false;
                to_pass.insert(*it);
                path[*it].erase(cur);
            }
        }
        return (int)passed.size()==n;
    }
};
