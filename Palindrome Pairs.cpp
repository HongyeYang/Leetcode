class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        //prepare data -structure
        unordered_map<string,int>m;
        set<int>s;
        vector<vector<int>>res;
        //fill in the unordered_map and set
        for(int i=0;i<words.size();i++){
            m[words[i]]=i;
            s.insert(words[i].size());
        }
        
        //interate for fall word in the vector
        for(int i=0;i<words.size();i++){
            string t=words[i];
            reverse(t.begin(),t.end());
            if(m.count(t)&&m[t]!=i)res.push_back({i,m[t]});
            int len=t.size();
            auto a=s.find(len);
            set<int>::iterator it=s.begin();
            for(;it!=a;it++){
                int d=*it;
                if(isValid(t,0,len-d-1)&&m.count(t.substr(len-d)))res.push_back({i,m[t.substr(len-d)]});
                if(isValid(t,d,len-1)&&m.count(t.substr(0,d)))res.push_back({m[t.substr(0,d)],i});
            }
        }
        return res;
    }
    bool isValid(string &s,int left,int right){
        while(left<right){
            if(s[left++]!=s[right--])return false;
        }
        return true;
    }
};
