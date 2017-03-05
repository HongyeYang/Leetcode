class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        map<int,int>m;
        for(vector<int>&v:updates){
            m[v[0]]+=v[2];
            m[v[1]+1]-=v[2];
        }
        vector<int>res(length,0);
        int sum=0;
        for(int i=0;i<length;i++){
            if(m.count(i))sum+=m[i];
            res[i]=sum;
        }
        return res;
    }
};
