class Solution {
public:
    unordered_map<string,vector<int>>roc;
    vector<int> diffWaysToCompute(string input) {
        int len=input.size();
        vector<int>res;
        for(int i=0;i<len;i++){
            if(input[i]=='+'||input[i]=='-'||input[i]=='*'){
                vector<int>left;
                vector<int>right;
                if(roc.find(input.substr(0,i))!=roc.end())left=roc[input.substr(0,i)];
                else left=diffWaysToCompute(input.substr(0,i));
                if(roc.find(input.substr(i+1))!=roc.end())right=roc[input.substr(i+1)];
                else right=diffWaysToCompute(input.substr(i+1));
                for(int j=0;j<left.size();j++){
                    for(int k=0;k<right.size();k++){
                        if(input[i]=='+')res.push_back(left[j]+right[k]);
                        else if(input[i]=='-')res.push_back(left[j]-right[k]);
                        else res.push_back(left[j]*right[k]);
                    }
                }
            }
        }
        if(!res.size())res.push_back(stoi(input));
        roc[input]=res;
        return res;
    }
};
