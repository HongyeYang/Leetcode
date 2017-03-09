class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int len=nums.size();
        vector<int>res(len,0);
        int i=0,j=len-1;
        int k=a>0?len-1:0;
        while(i<=j){
            if(a>0){
                res[k--]=trans(nums[i],a,b,c)>trans(nums[j],a,b,c)?trans(nums[i++],a,b,c):trans(nums[j--],a,b,c);
            }
            else{
                res[k++]=trans(nums[i],a,b,c)<trans(nums[j],a,b,c)?trans(nums[i++],a,b,c):trans(nums[j--],a,b,c);
            }
        }
        return res;
    }
    
    int trans(int &x,int &a, int &b,int &c){
        return a*x*x+b*x+c;
    }
};
