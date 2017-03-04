class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        return dfs(nestedList,1);
    }
    
    int dfs(vector<NestedInteger>& nestedList,int weight){
        if(nestedList.size()==0)return 0;
        int res=0;
        for(NestedInteger &n:nestedList){
            if(n.isInteger())res+=(weight*n.getInteger());
            else res+=dfs(n.getList(),weight+1);
        }
        return res;
    }
    
};
