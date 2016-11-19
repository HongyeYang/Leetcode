class Solution {
public:
    int maxArea(vector<int>& height) {
        int w=height.size();
        int i=0,j=w-1,res=0,cur=0;
        while(i<j){
            cur=(j-i)*min(height[i],height[j]);
            res=max(res,cur);
            if(height[i]>height[j])j--;
            else i++;
        }
        return res;
    }
};
