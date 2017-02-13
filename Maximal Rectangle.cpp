class Solution {
public:
    int maxiRecInHist(vector<int>&heights){
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
        heights.pop_back();
        return res;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();
        if(!m)return 0;
        int n=matrix[0].size();
        if(!n)return 0;
        vector<int>heights(n,0);
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0')heights[j]=0;
                else heights[j]++;
            }
            res=max(res,maxiRecInHist(heights));
        }
        return res;
    }
};
