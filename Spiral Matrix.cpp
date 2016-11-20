class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int h=matrix.size();
        if(!h)return res;
        int w=matrix[0].size();
        int a=0,lim=min((h+1)/2,(w+1)/2);
        for(;a<lim;a++){
            int left=a,right=w-a-1,up=a,down=h-1-a;
            if(up==down)for(int i=left;i<=right;i++)res.push_back(matrix[up][i]);
            else if(left==right)for(int i=up;i<=down;i++)res.push_back(matrix[i][right]);
            else{
            //up
            for(int i=left;i<right;i++)res.push_back(matrix[up][i]);
            //right
            for(int i=up;i<down;i++)res.push_back(matrix[i][right]);
            //down
            for(int i=right;i>left;i--)res.push_back(matrix[down][i]);
            //left
            for(int i=down;i>up;i--)res.push_back(matrix[i][left]);
            }
        }
        return res;
    }
};
