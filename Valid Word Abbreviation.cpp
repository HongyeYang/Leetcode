class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int j=0;
        for(int i=0;i<abbr.size();i++){
            if(j>=(int)word.size())return false;
            if(islower(abbr[i])){
                if(abbr[i]!=word[j++])return false;
            }
            else if(isdigit(abbr[i])){
                if(abbr[i]=='0')return false;
                int start=i;
                while(i<abbr.size()&&isdigit(abbr[i]))i++;
                j+=stoi(abbr.substr(start,i-start));
                i--;
            }
        }
        return j==word.size();
    }
};
