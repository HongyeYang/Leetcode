class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int>m1;
        unordered_map<int,int>m2;
        int n=A.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m1[A[i]+B[j]]++;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m2[C[i]+D[j]]++;
            }
        }
        int res=0;
        unordered_map<int,int>::iterator it;
        it=m1.begin();
        for(;it!=m1.end();it++){
            if(m2.find(-(it->first))!=m2.end()){
                res+=((it->second)*(m2[-(it->first)]));
            }
        }
        return res;
    }
};
