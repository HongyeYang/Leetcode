class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len=s.size();
        if(len<=10)return {};
        unordered_map<char,int>dict;
        dict['A']=1;
        dict['C']=2;
        dict['G']=3;
        dict['T']=4;
        int cur=0;
        vector<string>res;
        unordered_map<int,int>roc;
        int i=0;
        for(;i<10;i++){
            cur=(cur<<3)|dict[s[i]];
        }
        cur&=0x7fffffff;
        roc[cur]=1;
        while(i<len){
            cur=0x3fffffff&((cur<<3)|dict[s[i++]]);
            if(roc.find(cur)!=roc.end()){
                if(roc[cur]==1)res.push_back(s.substr(i-10,10));
                roc[cur]++;
            }
            else{
                roc[cur]=1;
            }
        }
        return res;
    }
};
