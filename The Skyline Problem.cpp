class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int>s{0};
        vector<pair<int,int>>points;
        for(auto &b:buildings){
            points.push_back({b[0],-b[2]});
            points.push_back({b[1],b[2]});
        }
        sort(points.begin(),points.end());
        int cur=0,pre=0;
        vector<pair<int,int>>res;
        for(auto &p:points){
            if(p.second<0)s.insert(-p.second);
            else s.erase(s.find(p.second));
            cur=*s.rbegin();
            if(cur!=pre){
                res.push_back({p.first,cur});
                pre=cur;
            }
        }
        return res;
    }
};
