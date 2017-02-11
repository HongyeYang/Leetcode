class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<3)return 0;
        stack<pair<int,int>>s;
        int res=0;
        for(int i=0;i<height.size();i++){
            while(!s.empty()&&s.top().first<height[i]){
                int base=s.top().first;
                s.pop();
                if(!s.empty())res+=(min(s.top().first,height[i])-base)*(i-s.top().second-1);
            }
            s.push({height[i],i});
        }
        return res;
    }
};
