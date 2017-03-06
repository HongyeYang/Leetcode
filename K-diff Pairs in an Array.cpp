class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res=0;
        if(k<0)return res;
        unordered_map<int,int>roc;
        for(int n:nums)roc[n]++;
        auto it=roc.begin();
        while(it!=roc.end()){
            if(k==0){
                if(it->second>1)res++;
            }
            else{
                if(roc.count(it->first+k))res++;
                if(roc.count(it->first-k))res++;
            }
            roc.erase(it);
            it=roc.begin();
            
        }
        return res;
    }
};
