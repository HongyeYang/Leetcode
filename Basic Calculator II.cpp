class Solution {
public:
    int calculate(string s) {
        int len=s.size();
        vector<int>roc;
        vector<int>opt;
        int i=0;
        while(i<len){
            while(i<len&&s[i]==' ')i++;
            if(i>=len)break;
            if(s[i]<='9'&&s[i]>='0'){
                int j=i;
                while(j<len&&(s[j]<='9'&&s[j]>='0'))j++;
                roc.push_back(stoi(s.substr(i,j-i)));
                i=j;
            }
            else{
                if(s[i]=='+'){opt.push_back(1);i++;}
                else if(s[i]=='-'){opt.push_back(-1);i++;}
                else {
                    char tep=s[i];
                    i++;
                    while(s[i]==' ')i++;
                    int j=i;
                    while(j<len&&(s[j]<='9'&&s[j]>='0'))j++;
                    int post=stoi(s.substr(i,j-i)),pre=roc.back();
                    if(tep=='*')roc[roc.size()-1]=pre*post;
                    else roc[roc.size()-1]=pre/post;
                    i=j;
                }   
            }
        }
        int res=roc[0];
        
        len=roc.size();
        for(int k=1;k<len;k++){
            if(opt[k-1]==1)res+=roc[k];
            else res-=roc[k];
        }
        return res;
    }
};
