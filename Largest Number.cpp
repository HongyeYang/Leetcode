class Solution {
public:
    static bool cmp(string s1,string s2){
        int len1=s1.size(), len2=s2.size(),c=0,c1=0,c2=0;
        while(c<len1+len2){
            if(s1[c1]>s2[c2])return true;
            else if(s1[c1]<s2[c2])return false;
            else {c1++;c2++;c++;}
            if(c1>=len1)c1=0;
            if(c2>=len2)c2=0;
        }
        return true;
    }
    string largestNumber(vector<int>& nums) {
        vector<string>roc;
        bool flag=false;
        for(int c:nums){
            if(c)flag=true;
            roc.push_back(to_string(c));
        }
        if(!flag)return "0";
        sort(roc.begin(),roc.end(),cmp);
        string res;
        for(string s:roc)res+=s;
        return res;
        
    }
};
