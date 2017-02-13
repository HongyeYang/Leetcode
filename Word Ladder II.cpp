class Solution {
public:
    bool check_connect(string &s1,string &s2){
        int cnt=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])cnt++;
            if(cnt>1)return false;
        }
        return cnt==1;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord.size()==1)return {{beginWord,endWord}};
        
        //build the graph
        vector<vector<int>>graph(wordList.size(),vector<int>{});
        vector<int>begin;
        int target=-1;
        for(int i=0;i<wordList.size();i++){
            if(target<0&&wordList[i]==endWord)target=i;
            if(check_connect(beginWord,wordList[i])){
                begin.push_back(i);
            }
            
        }

        if(target<0||begin.size()==0)return {};
        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++){
                if(check_connect(wordList[i],wordList[j])){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
       
        
        
        //prepare for traversing the graph
        queue<int>pass;
        vector<bool>used(wordList.size(),false);
        vector<bool>pushed(wordList.size(),false);
        vector<vector<int>>indegree(wordList.size(),vector<int>{});
        for(int i=0;i<begin.size();i++){
            pass.push(begin[i]);
            used[begin[i]]=true;
            pushed[begin[i]]=true;
        }
        pass.push(-1);

        //BSF 
        while(pass.size()>1&&pushed[target]==false){
            vector<int>passed;
            while(pass.front()>=0){
                int cur=pass.front();
                pass.pop();
                for(int i=0;i<graph[cur].size();i++){
                    int next=graph[cur][i];
                    if(used[next]==false){
                        indegree[next].push_back(cur);
                        if(pushed[next]==false){
                            passed.push_back(next);
                            pass.push(next);
                            pushed[next]=true;
                        }
                    }
                }
            }
            
            for(int i=0;i<passed.size();i++){
                used[passed[i]]=true;
            }
            passed.clear();
            pass.pop();
            pass.push(-1);
        }




        //decode indegree to get the results
        bool flag=true;
        vector<vector<int>>res{{target}};
        
        while(flag){
            int ss=res.size();
            for(int i=0;i<ss;i++){
                int last=res[i].back();
                if(indegree[last].size()==0)flag=false;
                for(int j=0;j<indegree[last].size();j++){
                    if(j==0)res[i].push_back(indegree[last][j]);
                    else{
                        vector<int>tep(res[i].begin(),res[i].end()-1);
                        tep.push_back(indegree[last][j]);
                        res.push_back(tep);
                    }
                    
                }
            }
        }

 
        //from index to string
        vector<vector<string>>resstr;
        for(int i=0;i<res.size();i++){
            vector<string>curstr={beginWord};
            for(int j=res[i].size()-1;j>=0;j--){
                curstr.push_back(wordList[res[i][j]]);
            }
            resstr.push_back(curstr);
        }
        
        return resstr;
    }
};
