class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n=org.size();
        if(n==1&&(seqs.size()==0||seqs[0].size()==0))return false;
        vector<int>indegree(n+1,0);
        vector<vector<int>>path(n+1);
        bool valid=true;
        for(vector<int>&v:seqs){
            if(v.size()==1&&(v[0]>n||v[0]<0))return false;
            for(int i=0;i<(int)v.size()-1;i++){
                if(v[i]>n||v[i]<=0||v[i+1]<=0||v[i+1]>n)return false;
                path[v[i]].push_back(v[i+1]);
                indegree[v[i+1]]++;
            }
        }
        vector<int>expect;
        int cur=-1;
        for(int i=1;i<=n;i++){
            if(!indegree[i]){
                if(cur>0)return false;
                cur=i;
            }
        }

        expect.push_back(cur);
        while(expect.size()<org.size()){
            if(cur<0)return false;
            int next=-1;
            for(int i=0;i<path[cur].size();i++){
                int t=path[cur][i];
                indegree[t]--;
                if(indegree[t]==0){
                    if(next>0)return false;
                    next=t;
                }
            }
            cur=next;
            expect.push_back(cur);
        }
        return expect==org;
    }
};
