class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len=tokens.size();
        if(!len)return 0;
        stack<int>roc;
        int res=0;
        for(int i=0;i<len;i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int num1=roc.top();
                roc.pop();
                int num2=roc.top();
                roc.pop();
                if(tokens[i]=="+")res=num2+num1;
                else if(tokens[i]=="-")res=num2-num1;
                else if(tokens[i]=="*")res=num2*num1;
                else res=num2/num1;
                roc.push(res);
            }
            else{
                res=stoi(tokens[i]);
                roc.push(res);
            }
        }
        return res;
    }
};
