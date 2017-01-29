class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int maxCnt = 0;
        vector<int>roc(26,0);
        int res = 0;
        for(int i=0;i<s.size();i++){
            roc[s[i]-'A']++;
            maxCnt = max(maxCnt,roc[s[i]-'A']);
            while(i-start-maxCnt+1>k){
                roc[s[start]-'A']--;
                start++;
            }
            res = max(res,i-start+1);
        }
        return res;
    }
};
