class Solution {
public:
    vector<string> generatePalindromes(string s) {
        int len=s.size();
        vector<int>roc(128,0);
        for(char c:s)roc[c]++;
        char single=0;
        string m;
        for(int i=0;i<128;i++){
            if(roc[i]&1){
                if(single!=0)return {};
                single=(char)i;
            }
            m.append(roc[i]/2,(char)i);
        }
        
        vector<string>res;
        res.push_back(m);
        while(next_permutation(m)){
            res.push_back(m);
        }
        for(int i=0;i<res.size();i++){
            string t=res[i];
            reverse(t.begin(),t.end());
            if(single!=0)res[i].push_back(single);
            res[i]+=t;
        }
        return res;
    }
    
    bool next_permutation(string &m){
        int len=m.size();
        int i=len-2,j=len-1;
        while(i>=0&&m[i]>=m[j]){
            i--;j--;
        }
        if(i<0)return false;
        int k=len-1;
        while(k>=0&&m[k]<=m[i])k--;
        swap(m[i],m[k]);
        reverse(m.begin()+j,m.end());
        return true;
    }
};
