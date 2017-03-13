class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>dict(wordList.begin(),wordList.end());
        if(!dict.count(endWord))return {};
        unordered_set<string>start{beginWord};
        unordered_set<string>end{endWord};
        unordered_map<string,vector<string>>path;
        vector<vector<string>>res;
        vector<string>ladder={beginWord};
        if(search_path(true,start,end,path,dict)){
            gen_ladders(beginWord,endWord,path,ladder,res);
            return res;
        }
        
        return {};
    }
    
    bool search_path(bool flip,unordered_set<string>&start,unordered_set<string>&end,unordered_map<string,vector<string>>&path,unordered_set<string>&dict){
        flip=!flip;
        if(start.empty())return false;
        if((int)start.size()>(int)end.size())return search_path(flip,end,start,path,dict);
        
        for(string word:start)dict.erase(word);
        for(string word:end)dict.erase(word);
        
        unordered_set<string>middleLayer;
        bool found=false;
        for(string word:start){
            string origin=word;
            for(int i=0;i<(int)origin.size();i++){
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(end.count(word)){
                        flip?path[word].push_back(origin):path[origin].push_back(word);
                        found=true;
                    }
                    else if(!found&&dict.count(word)){
                        flip?path[word].push_back(origin):path[origin].push_back(word);
                        middleLayer.insert(word);
                    }
                }
                word[i]=origin[i];
            }
        }
        if(found)return true;
        return found||search_path(flip,end,middleLayer,path,dict);
    }
    
    void gen_ladders(string &start,string &end,unordered_map<string,vector<string>>&path,vector<string>&ladder,vector<vector<string>>&res){
        if(start==end){
            res.push_back(ladder);
            return;
        }
        
        for(string &word:path[start]){
            ladder.push_back(word);
            gen_ladders(word,end,path,ladder,res);
            ladder.pop_back();
        }
        return;
    }
};
