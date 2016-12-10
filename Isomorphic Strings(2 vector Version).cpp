class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int len1=s.size(),len2=t.size();
        if(len1!=len2)return false;
        vector<int>m1(256,0);
        vector<int>m2(256,0);
        for(int i=0;i<len1;i++){
            if(m1[s[i]]!=m2[t[i]])return false;
            m1[s[i]]=i+1;
            m2[t[i]]=i+1;
        }
        return true;
    }
};
