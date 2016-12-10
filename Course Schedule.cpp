class Solution {
public:
    bool check(int tar, vector<bool>& roc, vector<vector<int>>&req){
        for(int c:req[tar]){
            if(!roc[c])return false;
        }
        return true;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool>roc(numCourses,true);
        vector<vector<int>>path(numCourses,vector<int>{});
        vector<vector<int>>req(numCourses,vector<int>{});
        for(auto c:prerequisites){
            path[c.second].push_back(c.first);
            req[c.first].push_back(c.second);
            roc[c.first]=false;
        }
        queue<int>pass;
        for(int i=0;i<numCourses;i++)if(roc[i])pass.push(i);
        while(!pass.empty()){
            int cur=pass.front();
            pass.pop();
            for(int c:path[cur]){
                if(roc[c])continue;
                if(check(c,roc,req)){
                    roc[c]=true;
                    pass.push(c);
                }
            }
        }
        for(bool cc:roc)if(!cc)return false;
        return true;
    }
};
