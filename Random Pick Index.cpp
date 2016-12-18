class Solution {
public:
    Solution(vector<int> nums) {
        roc=nums;
    }
    
    int pick(int target) {
        int res=0,count=1;
        for(int i=0;i<roc.size();i++){
            if(roc[i]==target){
                if(rand()%count==0)res=i;
                count++;
            }
        }
        return res;
    }
private:
vector<int> roc;
};
