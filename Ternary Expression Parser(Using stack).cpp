class Solution {
public:
    string parseTernary(string expression) {
        string res=expression;
        stack<int>st;
        for(int i=0;i<expression.size();i++){
            if(expression[i]=='?')st.push(i);
        }
        while(!st.empty()){
            int t=st.top();
            st.pop();
            if(res[t-1]=='T')res=res.substr(0,t-1)+res.substr(t+1,1)+res.substr(t+4);
            else res=res.substr(0,t-1)+res.substr(t+3);
        }
        return res;
    }
};
