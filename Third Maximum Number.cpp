class Solution {
public:
    static bool cmp(int a, int b){
        return a>b;
    }
    int thirdMax(vector<int>& nums) {
        vector<int>roc;
        for(int c:nums){
            if(roc.size()<3){
                if(roc.size()>0&&c>roc[0])roc.insert(roc.begin(),c);
                else if(roc.size()>1&&c<roc[0]&&c>roc[1])roc.insert(roc.begin()+1,c);
                else if(roc.size()==0||c<roc.back())roc.push_back(c);
            }
            else{
                if(c>roc[0]){
                    roc[2]=roc[1];
                    roc[1]=roc[0];
                    roc[0]=c;
                }
                else if(c>roc[1]&&c!=roc[0]){
                    roc[2]=roc[1];
                    roc[1]=c;
                }
                else if(c>roc[2]&&c!=roc[1]&&c!=roc[0]){
                    roc[2]=c;
                }
            }
        }
        return roc.size()<3?roc[0]:roc[2];
    }
};
