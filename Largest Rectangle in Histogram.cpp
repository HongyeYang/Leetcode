class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        stack<int>st;
        heights.push_back(0);
        for(int i=0;i<heights.size();i++){
            if(st.empty()||heights[st.top()]<=heights[i])st.push(i);
            else{
                int cur=0;
                while(!st.empty()&&heights[st.top()]>=heights[i]){
                    int kk=st.top();
                    st.pop();
                    cur=max(cur,heights[kk]*(st.empty()?i:(i-st.top()-1)));
                }
                res=max(res,cur);
                st.push(i);
            }
        }
        return res;
    }
};
