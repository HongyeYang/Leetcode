class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        unordered_map<int,unordered_map<int,int>>rocB;
        unordered_set<int>Bcols;
        for(int i=0;i<B.size();i++){
            for(int j=0;j<B[0].size();j++){
                if(B[i][j])rocB[i][j]=B[i][j];
            }
        }
        
        vector<vector<int>>res(A.size(),vector<int>(B[0].size(),0));
        for(int i=0;i<A.size();i++){
            for(int j=0;j<A[0].size();j++){
                if(!A[i][j]||!rocB.count(j))continue;
                auto it=rocB[j].begin();
                for(;it!=rocB[j].end();it++){
                    res[i][it->first]+=(A[i][j]*(it->second));
                }
            }
        }
        return res;
    }
};
