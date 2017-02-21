class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=haystack.size(),n=needle.size();
        //corner cases
        if(n==0)return 0;
        if(m<n)return -1;
        //build next vector
        vector<int>next(n+1,0);
        next[0]=-1;
        for(int i=1;i<=n;i++){
            int j=next[i-1];
            while(j>0&&needle[i-1]!=needle[j])j=next[j];
            next[i]=j+(needle[i-1]==needle[max(0,j)]);
        }

        //matching
        int j=0;
        for(int i=0;i<m;i++){
            while(j&&haystack[i]!=needle[j])j=next[j];
            if(haystack[i]==needle[j]){
                j++;
                if(j==n)return i-n+1;
            }
        }
        return -1;
    }
};
