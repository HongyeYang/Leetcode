class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()<2)return 0;
        stack<int>st;
        int res=0;
        st.push(-1);
        for(int i=0;i<s.size();i++){
            if(st.top()!=-1&&s[i]==')'&&s[st.top()]=='('){
                st.pop();
                res=max(res,i-st.top());
            }
            else st.push(i);
        }
        return res;
    }
};
