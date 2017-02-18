class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string>s;
        int min_x=INT_MAX,min_y=INT_MAX,max_x=INT_MIN,max_y=INT_MIN;
        int area=0;
        for(auto &v:rectangles){
            area+=((v[2]-v[0])*(v[3]-v[1]));
            
            min_x=min(min_x,v[0]);
            min_y=min(min_y,v[1]);
            max_x=max(max_x,v[2]);
            max_y=max(max_y,v[3]);
            
            string p1=to_string(v[0])+","+to_string(v[1]);
            string p2=to_string(v[2])+","+to_string(v[3]);
            string p3=to_string(v[0])+","+to_string(v[3]);
            string p4=to_string(v[2])+","+to_string(v[1]);
            
            auto pt1=s.find(p1);
            auto pt2=s.find(p2);
            auto pt3=s.find(p3);
            auto pt4=s.find(p4);
            
            if(pt1!=s.end())s.erase(pt1);
            else s.insert(p1);
            
            if(pt2!=s.end())s.erase(pt2);
            else s.insert(p2);
            
            if(pt3!=s.end())s.erase(pt3);
            else s.insert(p3);
            
            if(pt4!=s.end())s.erase(pt4);
            else s.insert(p4);
        }
        string plb=to_string(min_x)+","+to_string(min_y);
        string prt=to_string(max_x)+","+to_string(max_y);
        string plt=to_string(min_x)+","+to_string(max_y);
        string prb=to_string(max_x)+","+to_string(min_y);
        
        if(!s.count(plb)||!s.count(prt)||!s.count(plt)||!s.count(prb)||s.size()!=4)return false;
        return area==((max_x-min_x)*(max_y-min_y));
    }
};
