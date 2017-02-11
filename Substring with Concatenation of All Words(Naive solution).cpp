class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int lens=s.size(), numw=words.size(),lenw=words[0].size();
        if(!lens||!numw||lens<lenw*numw)return {};
        unordered_map<string,int>dict;
        
        for(string &w:words){
            dict[w]++;
        }
        vector<int>res;
        for(int i=0;i<=lens-numw*lenw;i++){
            unordered_map<string,int>ndict;
            int count=0;
            int cur=i;
            for(;cur<lens;cur+=lenw){
                string c=s.substr(cur,lenw);
                if(dict.find(c)!=dict.end()){
                    ndict[c]++;
                    if(ndict[c]<=dict[c]){
                        count++;
                        if(count==words.size()){
                            res.push_back(i);
                            ndict.clear();
                            break;
                        }
                    }
                    else{
                        ndict.clear();
                        break;
                    }
                }
                else{
                    ndict.clear();
                    break;
                }
            }
        }
        return res;
    }
};
