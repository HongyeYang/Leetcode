class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int mask=0,maxnum=0;
        for(int i=31;i>=0;i--){
            mask|=(1<<i);
            set<int>roc;
            for(int j:nums){
                roc.insert(mask&j);
            }
            int temp=maxnum|(1<<i);
            for(int kk:roc){
                if(roc.find(kk^temp)!=roc.end()){
                    maxnum=temp;
                    break;
                }
            }
        }
        return maxnum;
    }
};
