class Solution {
public:
    void input_res(vector<string>&res,int &left,vector<string>&cur,int &maxWidth){
        left++;
        string r=cur[0];
        int snum=cur.size();
        int space=left/max(1,(snum-1));
        int l=left%max(1,(snum-1));
        string sp(space+1,' ');
        for(int j=1;j<snum;j++){
            r+=sp;
            if(j<=l)r.push_back(' ');
            r+=cur[j];
        }
        while(r.size()<maxWidth)r.push_back(' ');
        res.push_back(r);
        cur.clear();
        r.clear();
        left=maxWidth;
        return;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string>res;
        vector<string>cur;
        int left=maxWidth;
        for(int i=0;i<words.size();i++){
            int curlen=words[i].size();
            if(left<curlen){
                input_res(res,left,cur,maxWidth);
            }
            cur.push_back(words[i]);
            left=left-words[i].size()-1;
        }
        
        string r="";
        for(int i=0;i<cur.size();i++){
            r+=cur[i];
            r.push_back(' ');
        }
        while(r.size()<maxWidth)r.push_back(' ');
        while(r.size()>maxWidth)r.pop_back();
        res.push_back(r);
        return res;
    }
};
