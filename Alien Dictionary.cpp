class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_set<char>letters;
        int n=words.size();
        for(int i=0;i<n;i++)letters.insert(words[i].begin(),words[i].end());
        //building order pairs
        unordered_set<string>orders;
        //extract letter order info from two neighboring words
        for(int i=0;i<n-1;i++){
            int minlen=min((int)words[i].size(),(int)words[i+1].size());
            for(int j=0;j<minlen;j++){
                if(words[i][j]!=words[i+1][j]){
                    string pp;
                    pp.push_back(words[i][j]);
                    pp.push_back(words[i+1][j]);
                    orders.insert(pp);
                    break;
                }
            }
        }
        vector<int>indegree(128,0);
        unordered_map<char,string>path;
        for(string a:orders){
            indegree[a[1]]++;
            path[a[0]].push_back(a[1]);
        }
        queue<char>q;
        for(char c:letters)if(indegree[c]==0)q.push(c);
        string res;
        while(!q.empty()){
            char cur=q.front();
            q.pop();
            res.push_back(cur);
            for(char c:path[cur]){
                indegree[c]--;
                if(indegree[c]==0)q.push(c);
            }
            
        }
        return res.size()==letters.size()?res:"";
    }
};
