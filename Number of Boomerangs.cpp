class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n=points.size();
        if(n<3)return 0;
        int res=0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>roc;
            for(int j=0;j<n;j++){
                if(i!=j){
                    int dist=(points[i].first-points[j].first)*(points[i].first-points[j].first)+(points[i].second-points[j].second)*(points[i].second-points[j].second);
                    roc[dist]++;
                }
            }
            unordered_map<int,int>::iterator it;
            it=roc.begin();
            for(;it!=roc.end();it++){
                if(it->second>1)res+=((it->second)*(it->second-1));
            }
        }
    return res;
    }
};
