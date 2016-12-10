class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>>path(numCourses,vector<int>{});
        vector<int>indegree(numCourses,0);
        vector<int>res;
        queue<int>pass;
        for(auto& c:prerequisites){
            path[c.second].push_back(c.first);
            indegree[c.first]++;
        }
        for(int i=0;i<numCourses;i++)if(!indegree[i])pass.push(i);
        while(!pass.empty()){
            int cur=pass.front();
            pass.pop();
            res.push_back(cur);
            for(int c:path[cur]){
                indegree[c]--;
                if(!indegree[c]){
                    pass.push(c);
                }
                
            }
        }
        for(int c:indegree)if(c)return {};
        return res;
    }
};
