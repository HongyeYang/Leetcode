class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>res;
        while(rowIndex>-1){
            for(int i=res.size()-1;i>0;i--){
                res[i]=res[i]+res[i-1];
            }
            res.push_back(1);
            rowIndex--;
        }
        return res;
    }
};
