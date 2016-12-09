class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res=0,count=0;
        for(int c:nums){
            if(!count){
                res=c;
                count++;
            }
            else{
                if(res==c)count++;
                else count--;
            }
        }
        return res;
    }
};
