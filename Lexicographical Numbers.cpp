class Solution {
public:
    vector<int> lexicalOrder(int n) {
        if(n<1)return {};
        vector<int>res(n);
        int cur=1;
        for(int i=0;i<n;i++){
            res[i]=cur;
            if(cur*10<=n)cur*=10;
            else{
                if(cur==n)cur/=10;
                cur++;
                while(cur%10==0)cur/=10;
            }
        }
        return res;
    }
};
