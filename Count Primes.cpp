class Solution {
public:
    int countPrimes(int n) {
        vector<bool>roc(n,true);
        roc[0]=false;roc[1]=false;
        int limit=sqrt(n);
        for(int i=2;i<=limit;i++){
            if(roc[i]){
                for(int j=i*i;j<n;j+=i){
                    roc[j]=false;
                }
            }
        }
        int res=0;
        for(bool c:roc)if(c)res++;
        return res;
    }
};
