class Solution {
public:
    string removeDuplicateLetters(string s) {
        int m[128]={0},visited[128]={0};
        for(char c:s)m[c]++;
        string res="0";
        
        for(char c:s){
            if(visited[c]!=0){
                m[c]--;
                continue;
            }
            while(res.back()>c&&m[res.back()]){
                visited[res.back()]=0;
                res.pop_back();
            }
            res.push_back(c);
            m[c]--;
            visited[c]=1;
        }
        return res.substr(1);
    }
};
