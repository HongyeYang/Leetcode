class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>>roc;
        for(string &s:strings){
            string t;
            int d=s[0]-'a';
            for(char c:s){
                c-=d;
                while(c<'a')c+=26;
                t.push_back(c);
            }
            roc[t].push_back(s);
        }
        vector<vector<string>>res;
        auto it=roc.begin();
        for(;it!=roc.end();it++){
            res.push_back(it->second);
        }
        return res;
    }
};
