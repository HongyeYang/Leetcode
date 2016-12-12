class Solution {
public:
    static bool cmp(int i, int j){
        return i>j;
    }
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),cmp);
        int len=citations.size();
        for(int i=0;i<len;i++)if(citations[i]<i+1)return i;
        return len;
    }
};
