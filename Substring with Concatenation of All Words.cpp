class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int lens=s.size(),numw=words.size(),lenw=words[0].size();
        if(!lens||!lenw||lens<lenw*numw)return {};
        unordered_map<string,int>dict;
        for(string &w:words){
            dict[w]++;
        }
        vector<int>res;
        for(int i=0;i<lenw;i++){
            unordered_map<string,int>udict;
            int left=i;
            int count=0;
            for(int j=i;j<lens;j+=lenw){
                string cur=s.substr(j,lenw);
                if(dict.find(cur)!=dict.end()){
                    udict[cur]++;
                    if(udict[cur]<=dict[cur]){
                        count++;
                        if(count==words.size()){
                            res.push_back(left);
                            udict[s.substr(left,lenw)]--;
                            left+=lenw;
                            count--;
                        }
                    }
                    else{
                        while(udict[cur]>dict[cur]){
                            udict[s.substr(left,lenw)]--;
                            left+=lenw;
                            count--;
                        }
                        count++;
                    }
                    
                }
                else{
                    udict.clear();
                    count=0;
                    left=j+lenw;
                }
            }
        }
        return res;
    }
};
