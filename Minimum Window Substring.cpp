class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>dict;
        for(char c:t){
            dict[c]++;
        }
        int count=dict.size();
        int left=0,right=0;
        int rleft=-1;
        int ss=INT_MAX;
        unordered_map<char,int>udict;
        for(;right<s.size();right++){
            if(dict.find(s[right])!=dict.end()){
                udict[s[right]]++;
                if(udict[s[right]]==dict[s[right]])count--;
                if(count<=0){
                    while(dict.find(s[left])==dict.end()||udict[s[left]]>dict[s[left]]){
                        if(dict.find(s[left])!=dict.end()&&udict[s[left]]>dict[s[left]])udict[s[left]]--;
                        left++;
                    }
                    if((right-left+1)<ss){
                        ss=right-left+1;
                        rleft=left;
                    }
                }
            }
        }
        return rleft<0?"":s.substr(rleft,ss);
    }
};
