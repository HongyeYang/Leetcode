class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>roc;
        roc.insert(n);
        while(1){
            int next=0;
            while(n){
                next+=(n%10)*(n%10);
                n/=10;
            }
            n=next;
            if(n==1)return true;
            if(roc.find(n)!=roc.end())return false;
            else roc.insert(n);
        }
        return false;
    }
};
