// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if(!n)return -1;
        if(n==1)return 0;
        int res=0;
        for(int i=1;i<n;i++){
            if(res!=-1){
                if(knows(i,res)&&!knows(res,i))continue;
                res=-1;
            }
            int j=0;
            for(;j<i;j++){
                if(!knows(j,i)||knows(i,j))break;
            }
            if(i==j)res=i;
        }
        return res;
    }
};
