class Solution {
public:
    NestedInteger deserialize(string s) {
        int len=s.size();
        NestedInteger res=NestedInteger();
        if(!len)return res;
        if(s[0]!='[')return NestedInteger(stoi(s));
        if(len<3)return res;
        int i=1,start=1,cnt=0;
        while(i<len){
            if(cnt==0&&(s[i]==','||i==len-1)){
                res.add(deserialize(s.substr(start,i-start)));
                start=i+1;
            }
            else if(s[i]=='[')cnt++;
            else if(s[i]==']')cnt--;
            i++;
        }
        return res;
    }
};
