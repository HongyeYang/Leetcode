class Solution {
public:
    int factorial(int n){
        int res=1;
        while(n>0){
            res*=n;
            n--;
        }
        return res;
    }
    string getPermutation(int n, int k) {
        string res;
        string roc="123456789";
        int curde=0,cur=0;
        k--;
        while(n>1){
        curde=factorial(n-1);
        cur=k/curde;
        k=k%curde;
        res.push_back(roc[cur]);
        roc.erase(cur,1);
        n--;
        }
        res.push_back(roc[0]);
        return res;
    }
};
