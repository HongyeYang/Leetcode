class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        //a map that record current consering chars->last idx
        unordered_map<char,int>roc;
        int res=0;
        int left=0;
        for(int i=0;i<s.size();i++){
            if(roc.count(s[i])||(roc.size()<2)){
                roc[s[i]]=i;
            }
            else{
                res=max(res,i-left);
                unordered_map<char,int>::iterator e1=roc.begin();
                unordered_map<char,int>::iterator e2=e1++;
                unordered_map<char,int>::iterator e;
                if(e1->second<e2->second){
                    e=e1;
                }
                else e=e2;
                left=e->second+1;
                roc.erase(e);
                roc[s[i]]=i;
            }
        }
        res=max(res,(int)s.size()-left);
        return res;
    }
};
