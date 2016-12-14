class Solution {
public:
    vector<int> countBits(int num) {
        vector<int>res(num+1,0);
        int order=1;
        for(int i=1;i<=num;i++){
            if(i==order+order){
                res[i]=1;
                order<<=1;
            }
            else{
                res[i]=res[i-order]+1;
            }
        }
        return res;
    }
};
