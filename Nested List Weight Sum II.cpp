class Solution {
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int sum=0;
        int minw=0;
        return dfs(nestedList,-1,sum,minw)+(1-minw)*sum;
    }
    int dfs(vector<NestedInteger>&nestedList,int w,int &sum, int&minw){
        int res=0;
        minw=min(minw,w);
        for(NestedInteger &n:nestedList){
            if(n.isInteger()){
                sum+=n.getInteger();
                res+=w*n.getInteger();
            }
            else res+=dfs(n.getList(),w-1,sum,minw);
        }
        return res;
    }
};
