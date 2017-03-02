class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<int>roc(128,0);
        bool single=false;
        string half;
        char single_c=0;
        for(char c:s)roc[c]++;
        for(int i=0;i<128;i++){
            if(roc[i]&1){
                if(single)return {};
                else{
                    single=true;
                    single_c=(char)i;
                }
            }
            if(roc[i])half.append(roc[i]/2,i);
        }
        
        //generate permutations
        vector<string>res;
        vector<bool>used(half.size(),false);
        string cur;
        string mid;
        if(single_c)mid.push_back(single_c);
        dfs(half,cur,used,res,mid);
        return res;
    }
    
    void dfs(string &half, string &cur,vector<bool>&used,vector<string>&res,string &mid){
        if((int)cur.size()==(int)half.size()){
            res.push_back(cur+mid+string(cur.rbegin(),cur.rend()));
            return;
        }
        for(int i=0;i<half.size();i++){
            
            if(i>0&&half[i]==half[i-1]&&!used[i-1])continue;
            if(!used[i]){
                cur.push_back(half[i]);
                used[i]=true;
                dfs(half,cur,used,res,mid);
                used[i]=false;
                cur.pop_back();
            }
        }
        return;
    }
};
