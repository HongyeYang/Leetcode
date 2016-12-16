class Solution {
public:
    int lengthLongestPath(string input) {
        int len=input.size();
        if(!len)return 0;
        unordered_map<int,int>roc;
        roc[0]=0;
        bool flag=false;
        int cnt=1,res=0,start=0;
        for(int i=0;i<len;i++){
            if(input[i]!='\n'&&input[i]!='\t'){
                int start=i;
                while(i<len&&input[i]!='\n'){
                    if(input[i]=='.')flag=true;
                    i++;
                }
                if(flag){
                    res=max(res,i-start+roc[cnt-1]);
                    flag=false;
                }
                else roc[cnt]=roc[cnt-1]+i-start+1;
                cnt=1;
            }
            else{
                if(input[i]=='\t')cnt++;
            }
        }
        return res;
    }
};
