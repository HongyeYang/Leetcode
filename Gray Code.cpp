class Solution {
public:
    vector<int> grayCode(int n) {
        if(!n)return {0};
        vector<int>res={0,1};
        n--;
        while(n){
            int len=res.size();
            for(int i=len-1;i>=0;i--)res.push_back(len+res[i]);
            n--;
        }
        return res;
    }
};
