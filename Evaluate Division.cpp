class Solution {
public:
    bool DSF(double cur,unordered_map<string,unordered_map<string,double>>&roc,string src, string target,vector<double>&res,unordered_set<string>&used){
        if(roc.find(src)==roc.end())return false;
        if(roc[src].find(target)!=roc[src].end()){
                res.push_back(cur*roc[src][target]);
                return true;
            }
        for(auto &k:roc[src]){
            if(used.find(k.first)!=used.end())continue;
            used.insert(k.first);
            if(DSF(cur*k.second,roc,k.first,target,res,used))return true;
        }
        return false;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string,unordered_map<string,double>>roc;
        for(int i=0;i<equations.size();i++){
            roc[equations[i].first].insert({equations[i].second,values[i]});
            if(values[i])roc[equations[i].second].insert({equations[i].first,1/values[i]});
        }
        vector<double>res;
        for(auto &c:queries){
            unordered_set<string>used;
            double cur=1.0;
            used.insert(c.first);
            if(!DSF(cur,roc,c.first,c.second,res,used))res.push_back(-1);
        }
        return res;
    }
};
