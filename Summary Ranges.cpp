class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>res;
        int len=nums.size();
        if(!len)return res;
        pair<long,long>cur;
        cur.first=nums[0];
        for(int i=1;i<len;i++){
            if((long)nums[i]-(long)nums[i-1]>1){
                cur.second=nums[i-1];
                if(cur.first<cur.second)res.push_back(to_string(cur.first)+"->"+to_string(cur.second));
                else res.push_back(to_string(cur.first));
                cur.first=nums[i];
            }
        }
        cur.second=nums.back();
        if(cur.first<cur.second)res.push_back(to_string(cur.first)+"->"+to_string(cur.second));
        else res.push_back(to_string(cur.first));
        return res;
    }
};
