class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int>indegree(numCourses,0);
        vector<vector<int>>path(numCourses,vector<int>{});
        for(auto c:prerequisites){
            path[c.second].push_back(c.first);
            indegree[c.first]++;
        }
        queue<int>pass;
        for(int i=0;i<numCourses;i++)if(!indegree[i])pass.push(i);
        while(!pass.empty()){
            int cur=pass.front();
            pass.pop();
            for(int c:path[cur]){
                indegree[c]--;
                if(!indegree[c])pass.push(c);
            }
        }
        for(int cc:indegree)if(cc)return false;
        return true;
    }
};
