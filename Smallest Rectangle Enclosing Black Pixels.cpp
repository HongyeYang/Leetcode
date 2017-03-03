class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int left=y,right=y,up=x,down=x;
        dfs(image,x,y,left,right,up,down);
        return (right-left+1)*(down-up+1);
    }
    void dfs(vector<vector<char>>&image, int x, int y, int &left, int &right, int &up, int &down){
        image[x][y]='2';
        up=min(up,x);
        down=max(down,x);
        left=min(left,y);
        right=max(right,y);
        //up
        if(x>0&&image[x-1][y]=='1')dfs(image,x-1,y,left,right,up,down);
        //down
        if(x<(int)image.size()-1&&image[x+1][y]=='1')dfs(image,x+1,y,left,right,up,down);
        //left
        if(y>0&&image[x][y-1]=='1')dfs(image,x,y-1,left,right,up,down);
        //right
        if(y<(int)image[0].size()-1&&image[x][y+1]=='1')dfs(image,x,y+1,left,right,up,down);
        
        return;
    }
};
