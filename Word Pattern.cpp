class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int len=str.size();
        int lenp=pattern.size();
        if(!lenp&&(len))return false;
        unordered_map<string,char>roc;
        vector<bool>used(26,false);
        int i=0,k=0;
        while(i<len){
            while(i<len&&str[i]==' ')i++;
            if(i==len)break;
            int j=i;
            while(str[j]!=' ')j++;
            string cur=str.substr(i,j-i);
            i=j;
            if(roc.find(cur)!=roc.end()){
                if(roc[cur]!=pattern[k])return false;
            }
            else{
                if(used[pattern[k]-'a'])return false;
                used[pattern[k]-'a']=true;
                roc[cur]=pattern[k];
            }
            k++;
        }
        return k==lenp;
    }
};
