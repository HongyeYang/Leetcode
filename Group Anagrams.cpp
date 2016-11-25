class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int len=strs.size();
        if(!len)return {};
        unordered_map<string,int>roc;
        vector<vector<string>>res;
        int k=0;
        for(int i=0;i<len;i++){
            string cur=strs[i];
            sort(cur.begin(),cur.end());
        if(!i||roc.find(cur)==roc.end()){
            roc[cur]=k;
            res.push_back({strs[i]});
            k++;
        }
        else res[roc[cur]].push_back(strs[i]);
        }
        return res;
    }
};
