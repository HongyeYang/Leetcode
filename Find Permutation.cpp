class Solution {
public:
    vector<int> findPermutation(string s) {
        int n=(int)s.size()+1;
        vector<int>res(n,0);
        for(int i=1;i<=n;i++)res[i-1]=i;
        
        for(int i=0;i<n-1;i++){
            if(s[i]=='D'){
                int start=i;
                while(i<n-1&&s[i]=='D')i++;
                reverse(res.begin()+start,res.begin()+i+1);
            }
        }
        return res;
    }
};
