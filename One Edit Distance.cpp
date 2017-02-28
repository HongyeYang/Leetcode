class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int lens=s.size(),lent=t.size();
        if(abs(lens-lent)>1)return false;
        //change
        int dis=0;
        if(lens==lent){
            for(int i=0;i<lens;i++){
                if(s[i]!=t[i]){
                    dis++;
                    if(dis>1)return false;
                }
            }
        }
        //add
        else if(lens>lent){
            if(lent==0)return lens==1;
            int j=0;
            for(int i=0;i<lens;i++){
                if(s[i]!=t[j]){
                    dis++;
                    if(dis>1)return false;
                }
                else j++;
            }
        }
        //delete
        else return isOneEditDistance(t,s);
        return dis==1;
    }
};
