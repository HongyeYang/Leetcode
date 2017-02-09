class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        map<int,int>roc;
        for(int i=0;i<nums.size();i++){
            roc[-nums[i]]=i;
        }
        map<int,int>::iterator it=roc.begin();
        vector<string>res(nums.size(),"");
        int cnt=1;
        for(;it!=roc.end();it++){
            if(cnt<4){
                if(cnt==1)res[it->second]="Gold Medal";
                else if(cnt==2)res[it->second]="Silver Medal";
                else res[it->second]="Bronze Medal";
            }
            else res[it->second]=to_string(cnt);
            cnt++;
        }
        return res;
    }
};
