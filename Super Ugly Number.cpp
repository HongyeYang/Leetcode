class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int len=primes.size();
        vector<int>candidates(len,0);
        vector<int>ugly={1};
        int tep=1;
        while(--n){
            tep=INT_MAX;
            for(int i=0;i<len;i++){
                tep=min(tep,primes[i]*ugly[candidates[i]]);
            }
            ugly.push_back(tep);
            for(int i=0;i<len;i++){
                if(tep==primes[i]*ugly[candidates[i]])candidates[i]++;
            }
        }
        return tep;
    }
};
