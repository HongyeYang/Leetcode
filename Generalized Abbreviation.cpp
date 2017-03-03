class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        vector<string>res;
        dfs(word,res);
        return res;
    }
    void dfs(string word,vector<string>&res){
        int len=word.size();
        if(!len){
            res.push_back("");
            return;
        }
        if(len==1){
            res.push_back(word);
            res.push_back("1");
            return;
        }
        
        dfs(word.substr(1),res);
        int n=res.size();
        for(int i=0;i<n;i++){
            if(res[i][0]>='0'&&res[i][0]<='9'){
                string t=res[i];
                int k=1;
                while(k<t.size()&&isdigit(t[k]))k++;
                int tep=stoi(t.substr(0,k));
                tep++;
                res.push_back(to_string(tep)+t.substr(k));
                t.clear();
            }
            else res.push_back("1"+res[i]);
            res[i]=word[0]+res[i];
        }
        return;
    }
};
