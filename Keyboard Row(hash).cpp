class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        if(words.size()==0)return {};
        unordered_set<char> s1{'z','x','c','v','b','n','m'};
        unordered_set<char> s2{'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> s3{'q','w','e','r','t','y','u','i','o','p'};
        vector<unordered_set<char>>s{s1,s2,s3};
        vector<string>res;
        int flag=0;
        for(int i=0;i<words.size();i++){
            string &cur=words[i];
            if(s[0].find(tolower(cur[0]))!=s[0].end())flag=0;
            else if(s[1].find(tolower(cur[0]))!=s[1].end())flag=1;
            else if(s[2].find(tolower(cur[0]))!=s[2].end())flag=2;
            else continue;
            
            for(int j=1;j<cur.size();j++){
                if(s[flag].find(tolower(cur[j]))==s[flag].end()){
                    flag=-1;
                    break;
                }
            }
            if(flag>-1)res.push_back(cur);
        }
        return res;
    }
};
