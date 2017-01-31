class Solution {
public:
    static bool cmp(pair<int,int>p1,pair<int,int>p2){
        return p1.second<p2.second;
    }
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size()==0)return 0;
        sort(points.begin(),points.end(),cmp);
        int res=1;
        int last_shot = points[0].second;
        for(int  i=1;i<points.size();i++){
            if(points[i].first>last_shot){
                res++;
                last_shot=points[i].second;
            }
        }
        return res;
    }
};
