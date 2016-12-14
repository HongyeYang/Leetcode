class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string>res;
        unordered_map<string,multiset<string>>roc;
        for(auto c:tickets){
            roc[c.first].insert(c.second);
        }
        stack<string>s;
        s.push("JFK");
        while(!s.empty()){
            string cur=s.top();
            if(roc[cur].empty()){
                res.push_back(cur);
                s.pop();
            }
            else{
                s.push(*roc[cur].begin());
                roc[cur].erase(roc[cur].begin());
            }
        }
        return vector<string>(res.rbegin(),res.rend());
    }
};
