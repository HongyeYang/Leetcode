class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        vector<int>reputation(s2.size()+1,0);
        vector<int>nextIndex(s2.size()+1,0);
        int j=0,cnt=0;
        for(int m=1;m<=n1;m++){
            for(int i=0;i<s1.size();i++){
                if(s1[i]==s2[j]){
                    j++;
                    if(j==(int)s2.size()){
                        cnt++;
                        j=0;
                    }
                }
            }
            reputation[m]=cnt;
            nextIndex[m]=j;
            
            for(int start=0;start<m;start++){
                if(nextIndex[start]==j){
                    int interval=m-start;
                    int repeat=(n1-start)/interval;
                    int patternRep=repeat*(reputation[m]-reputation[start]);
                    int nonpatternRep=reputation[start+(n1-start)%interval];
                    return (patternRep+nonpatternRep)/n2;
                }
            }
        }
        return reputation[n1]/n2;
    }
};
