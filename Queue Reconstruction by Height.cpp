class Solution {
public:
    static bool cmp(pair<int,int>p1,pair<int,int>p2){
        if(p1.first==p2.first)return p1.second<p2.second;
        return p1.first>p2.first;
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(),people.end(),cmp);
        vector<pair<int,int>>res;
        for(auto&c:people){
            res.insert(res.begin()+c.second,c);
        }
        return res;
    }
};
