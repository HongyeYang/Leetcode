class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if(matrix.size()==0||matrix[0].size()==0)return 0;
        int m=matrix.size(),n=matrix[0].size(),res=INT_MIN;
        for(int i=0;i<n;i++){
            vector<int>sum(m,0);
            for(int j=i;j<n;j++){
                for(int kk=0;kk<m;kk++){
                    sum[kk]+=matrix[kk][j];
                }
                set<int>s{0};
                int cursum=0;
                for(int a:sum){
                    cursum+=a;
                    auto it=s.lower_bound(cursum-k);
                    if(it!=s.end())res=max(res,cursum-(*it));
                    s.insert(cursum);
                }
            }
        }
        return res;
    }
};
