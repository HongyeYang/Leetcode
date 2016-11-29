class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(!numRows)return{};
        vector<vector<int>>res;
        vector<int>cur;
        while(numRows){
            for(int i=cur.size()-1;i>=0;i--){
                if(i>0)cur[i]=cur[i]+cur[i-1];
            }
            cur.push_back(1);
            res.push_back(cur);
            numRows--;
        }
        return res;
    }
};
