class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int res=1;
        if(b.size()==0)return 0;
        for(int c:b){
            res=pow(res,10)*pow(a,c)%1337;
        }
        return res;
    }
    int pow(int a, int b){
        if(!b)return 1;
        if(b==1)return a%1337;
        return pow(a,b/2)*pow(a,b-b/2)%1337;
    }
};
