class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if(n==1)return{0};
        vector<unordered_set<int>>roc(n);
        for(auto& c:edges){
            roc[c.first].insert(c.second);
            roc[c.second].insert(c.first);
        }
        vector<int>leaves;
        for(int i=0;i<n;i++){
            if(roc[i].size()==1)leaves.push_back(i);
        }
        
        while(1){
            vector<int>next;
            for(int node:leaves){
                for(int neighbor:roc[node]){
                    roc[neighbor].erase(node);
                    if(roc[neighbor].size()==1)next.push_back(neighbor);
                }
            }
            if(next.empty())return leaves;
            leaves=next;
        }
    }
};
