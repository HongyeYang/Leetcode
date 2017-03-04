class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        unordered_map<int,unordered_set<int>>pp;
        int max_x=INT_MIN,min_x=INT_MAX;
        for(auto &p:points){
            max_x=max(max_x,p.first);
            min_x=min(min_x,p.first);
            pp[p.first].insert(p.second);
        }
        
        double y=((double)max_x+min_x)/2.0;
        for(auto &p:points){
            int t=2*y-p.first;
            if(!pp.count(t)||!pp[t].count(p.second))return false;
        }
        return true;
    }
};
