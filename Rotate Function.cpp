class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int len=A.size();
        int res=0,cur=0,sum=0;
        for(int i=0;i<len;i++){
            sum+=A[i];
            cur+=i*A[i];
        }
        res=cur;
        for(int i=1;i<len;i++){
            cur=cur+sum-len*A[len-i];
            res=max(res,cur);
        }
        return res;
    }
};
