class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()<2)return 0;
        stack<int>st;
        vector<int>roc(s.size()+1,0);
        int res=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(i);
            else{
                if(!st.empty()){
                    roc[i+1]=i-st.top()+1+roc[st.top()];
                    st.pop();
                }
                res=max(roc[i+1],res);
            }
        }
        return res;
    }
};
