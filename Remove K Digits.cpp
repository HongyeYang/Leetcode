class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        for(int i=0;i<num.size();i++){
            while(!st.empty()&&st.top()>num[i]&&(i-k<(int)st.size())){
                st.pop();
            }
            st.push(num[i]);
        }
        string res;
        while(st.size()>(int)num.size()-k)st.pop();
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        int start=0;
        while(start<res.size()&&res[start]=='0')start++;
        return start==(int)res.size()?"0":res.substr(start);
    }
};
