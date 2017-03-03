class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string> dictionary) {
        for(string &s:dictionary){
            if(!words.count(s)){
                roc[s2i(s)]++;
                words.insert(s);
            }
        }
    }
    int s2i(string &s){
        int res=(s[0]-'a')*26+(s.back()-'a');
        int len=s.size();
        res=res+(len<<15);
        return res;
    }
    bool isUnique(string word) {
        return !roc.count(s2i(word))||(words.count(word)&&roc[s2i(word)]==1);
    }
private:
unordered_map<int,int>roc;
unordered_set<string>words;
};
