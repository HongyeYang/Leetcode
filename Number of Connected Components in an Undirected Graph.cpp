class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<bool>passed(n,false);
        vector<unordered_set<int>>path(n,unordered_set<int>{});
        for(auto &p:edges){
            path[p.first].insert(p.second);
            path[p.second].insert(p.first);
        }
        
        int res=0;
        for(int i=0;i<n;i++){
            if(!passed[i]){
                res++;
                queue<int>to_pass;
                to_pass.push(i);
                while(!to_pass.empty()){
                    int cur=to_pass.front();
                    to_pass.pop();
                    passed[cur]=true;
                    auto it=path[cur].begin();
                    for(;it!=path[cur].end();it++){
                        if(!passed[*it]){
                            to_pass.push(*it);
                            path[*it].erase(cur);
                        }
                    }
                }
            }
        }
        return res;
    }
};
