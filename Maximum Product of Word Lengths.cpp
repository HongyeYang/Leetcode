class Solution {
public:
    int maxProduct(vector<string>& words) {
        int len=words.size();
        int res=0;
        vector<int>mask(len,0);
        for(int i=0;i<len;i++){
            for(char c:words[i]){
                mask[i]|=1<<(c-'a');
            }
        }
        for(int i=0;i<len-1;i++){
            for(int j=i+1;j<len;j++){
                if(!(mask[i]&mask[j])){
                    int m=words[i].size(),n=words[j].size();
                    res=max(res,m*n);
                }
            }
        }
        return res;
    }
};
