class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int len=machines.size();
        vector<int>sum(len+1,0);
        for(int i=0;i<len;i++){
            sum[i+1]=sum[i]+machines[i];
        }
        if(sum[len]%len)return -1;
        int avg=sum[len]/len;
        int res=0;
        for(int i=0;i<len;i++){
            int l=avg*i-sum[i];
            int r=avg*(len-i-1)-(sum[len]-sum[i+1]);
            if(l>0&&r>0)res=max(res,abs(r)+abs(l));
            else res=max(res,max(abs(r),abs(l)));
        }
        return res;
    }
};
