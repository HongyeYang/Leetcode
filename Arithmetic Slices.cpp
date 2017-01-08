class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<3)return 0;
        int step=A[1]-A[0],len=0,res=0;
        for(int i=2;i<A.size();i++){
            if(A[i]==step+A[i-1])len++;
            else{
                if(len>0)res+=(len+1)*len/2;
                len=0;
                step=A[i]-A[i-1];
            }
        }
        if(len>0)res+=(len+1)*len/2;
        return res;
    }
};
