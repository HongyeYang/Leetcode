class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if(points.size()<3)return points.size();
        int res=0;
        for(int i=0;i<points.size();i++){
            map<pair<int,int>,int>roc;
            int dup=1;
            for(int j=i+1;j<points.size();j++){
                //case 1 if points[i]==points[j]
                if(points[i].x==points[j].x&&points[i].y==points[j].y)dup++;
                else if(points[i].x==points[j].x)roc[{0,0}]++;
                else{
                    int a=points[i].x-points[j].x,b=points[i].y-points[j].y;
                    int g=gcd(a,b);
                    a/=g;
                    b/=g;
                    roc[{a,b}]++;
                }
            }
            res=max(res,dup);
             map<pair<int,int>,int>::iterator it=roc.begin();
             for(;it!=roc.end();it++){
                 res=max(res,it->second+dup);
             }
             
             roc.clear();
        }
        return res;
    }
    
    int gcd(int a,int b){
        return a==0?b:gcd(b%a,a);
    }
};
