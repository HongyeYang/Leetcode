class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int>x;
        vector<int>y;
        int m=grid.size();
        if(!m)return 0;
        int n=grid[0].size();
        if(!n)return 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    x.push_back(i);
                }
            }
        }
        for(int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                if(grid[i][j]==1)y.push_back(j);
            }
        }
        
        int left=0,right=x.size()-1;
        int res=0;
        while(left<right){
            res+=(x[right]-x[left]+y[right]-y[left]);
            left++;
            right--;
        }
        return res;
    }
};
