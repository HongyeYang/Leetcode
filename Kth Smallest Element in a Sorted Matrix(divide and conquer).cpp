class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
         int n=matrix.size();
         int left=matrix[0][0],right=matrix[n-1][n-1];
         while(left<right){
             int mid=(left+right)/2,cnt=0;
             for(int i=0;i<n;i++){
                 cnt+=(upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin());
             }
             if(cnt<k)left=mid+1;
             else right=mid;
         }
        return left;
    }
};
