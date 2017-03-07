class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        unordered_map<int,int>rows;
        unordered_map<int,int>cols;
        for(int i=0;i<picture.size();i++){
            int cnt=0;
            int cj=-1;
            for(int j=0;j<(int)picture[0].size();j++){
                if(picture[i][j]=='B'){
                    cnt++;
                    cj=j;
                    cols[j]++;
                }
            }
            if(cnt==1)rows[i]=cj;
        }
        int res=0;
        for(auto it=rows.begin();it!=rows.end();it++){
            if(cols[it->second]==1)res++;
        }
        return res;
    }
};
