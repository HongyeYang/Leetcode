class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        if(!m)return false;
        int n=matrix[0].size();
        if(!n)return false;
        int up=0,down=m-1,left=0,right=n-1,mid=0;
        while(up<=down){
            mid=(up+down)/2;
            if(matrix[mid][0]>target)down=mid-1;
            else if(mid<m-1&&matrix[mid+1][0]<=target)up=mid+1;
            else break;
        }
        int cet;
        while(left<=right){
            cet=(left+right)/2;
            if(matrix[mid][cet]>target)right=cet-1;
            else if(matrix[mid][cet]<target)left=cet+1;
            else return true;
        }
        return false;
    }
};
