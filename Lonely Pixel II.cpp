class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        unordered_map<string,pair<string,int>>rows;
        unordered_map<string,int>cols;
        
        int m=picture.size();
        if(!m)return 0;
        int n=picture[0].size();
        if(!n)return 0;
        string t(m,'W');
        for(int i=0;i<m;i++){
            int cnt=0;
            string cur;
            for(int j=0;j<n;j++){
                cur.push_back(picture[i][j]);
                if(picture[i][j]=='B')cnt++;
            }
            if(cnt==N){
                if(!rows.count(cur))rows[cur]={t,0};
                rows[cur].first[i]='B';
                rows[cur].second++;
            }
        }
        
        for(int j=0;j<n;j++){
            string cur;
            int cnt=0;
            for(int i=0;i<m;i++){
                if(picture[i][j]=='B'){
                    cnt++;
                    if(cnt>N)break;
                }
                cur.push_back(picture[i][j]);
            }
            if(cnt==N)cols[cur]++;
        }
        int res=0;
        for(auto it=rows.begin();it!=rows.end();it++){
            if(it->second.second==N){
                res+=N*cols[it->second.first];
            }
        }
        return res;
    }
};
