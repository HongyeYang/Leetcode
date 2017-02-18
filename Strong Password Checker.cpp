class Solution {
public:
    int strongPasswordChecker(string s) {
        int ToAdd=max(0,6-(int)s.size()),ToDelete=max(0,(int)s.size()-20),ToReplace=0;
        int Added=0,Deleted=0,NeedLower=1,NeedUpper=1,NeedDigit=1;
        for(int l=0,r=0;r<s.size();r++){
            if(isupper(s[r]))NeedUpper=0;
            if(islower(s[r]))NeedLower=0;
            if(isdigit(s[r]))NeedDigit=0;
            
            if(r-l==2){
                if(s[l]==s[l+1]&&s[l+1]==s[r]){
                    if(Added<ToAdd)Added++;
                    else ToReplace++;
                    l=r+1;
                }
                else l++;
            }
        }
        if(s.size()<=20)return max(ToAdd+ToReplace,NeedUpper+NeedLower+NeedDigit);
        
        ToReplace=0;
        vector<unordered_map<int,int>>roc(3);
        
        for(int l=0,r=0,len;r<=s.size();r++){
            if(r==s.size()||s[r]!=s[l]){
                if((len=r-l)>2)roc[len%3][len]++;
                l=r;
            }
        }
        
        for(int i=0;i<3;i++){
            unordered_map<int,int>::iterator it=roc[i].begin();
            for(;it!=roc[i].end();it++){
                if(i<2){
                    int numLetter=i+1;
                    int del=min(it->second,(ToDelete-Deleted)/numLetter);
                    it->second-=del;
                    Deleted+=(numLetter*del);
                    if(it->first-numLetter>2)roc[2][it->first-numLetter]+=del;
                }
                ToReplace+=(it->second*(it->first/3));
            }
        }
        int del=(ToDelete-Deleted)/3;
        return ToDelete+max(ToReplace-del,NeedUpper+NeedLower+NeedDigit);
    }
};
