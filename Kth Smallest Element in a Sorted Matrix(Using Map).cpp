class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size(),n=matrix[0].size();
        map<int,vector<pair<int,int>>>roc;
        roc[matrix[0][0]].push_back({0,0});
        int res=0;
        while(k--){
            res=roc.begin()->first;
            int i=roc.begin()->second.back().first,j=roc.begin()->second.back().second;
            roc.begin()->second.pop_back();
            if(roc.begin()->second.empty())roc.erase(roc.begin());
            if(i<m-1&&matrix[i+1][j]<INT_MAX){
                roc[matrix[i+1][j]].push_back({i+1,j});
                matrix[i+1][j]=INT_MAX;
            }
            if(j<n-1&&matrix[i][j+1]<INT_MAX){
                roc[matrix[i][j+1]].push_back({i,j+1});
                matrix[i][j+1]=INT_MAX;
            }
        }
        return res;
    }
};
