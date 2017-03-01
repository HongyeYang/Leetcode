class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        pair<int,int>border;
        return dfs(preorder,0,preorder.size()-1,border);
    }
    bool dfs(vector<int>&preorder, int start, int end, pair<int,int>&border){
        if(start>end)return true;
        if(start==end){
            border.first=preorder[start];
            border.second=preorder[start];
            return true;
        }
        
        //binary search to find the left-right boundary
        
        //find the boundary between left subtree and right substree
        int bond=-1;
        //no left substree
        if(preorder[start]<preorder[start+1])bond=start+1;
        //no right substree
        else if(preorder[start]>preorder[end])bond=end+1;
        //with bot left and right subtrees
        else{
            int left=start+1;
            int right=end;
            while(left<=right){
                int mid=left+(right-left)/2;
                if(preorder[mid]>preorder[start]){
                    if(preorder[mid-1]<preorder[start]){
                        bond=mid;
                        break;
                    }
                    right=mid-1;
                }
                else left=mid+1;
            }
            if(bond<0)bond=left;
        }
        pair<int,int>lb;
        pair<int,int>rb;
        if(bond>start+1){
            if(dfs(preorder,start+1,bond-1,lb)==false||lb.second>preorder[start])return false;
        }
        else lb.first=preorder[start];
        if(bond<=end){
            if(dfs(preorder,bond,end,rb)==false||rb.first<preorder[start])return false;
        }
        else rb.second=preorder[start];
        border.first=lb.first;
        border.second=rb.second;
        return true;
    }
};
