class Solution {
public:
    vector<int> constructRectangle(int area) {
        int res=sqrt(area);
        while(area%res){
            res--;
        }
        return {area/res,res};
    }
};
