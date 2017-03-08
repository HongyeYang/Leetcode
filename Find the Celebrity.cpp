// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        //first pass to find a candidate
        int res=0;
        for(int i=1;i<n;i++){
            if(knows(res,i))res=i;
        }
        //second pass to validate if the candidate is a real celebrity
        for(int i=0;i<n;i++){
            if(i!=res&&(knows(res,i)||!knows(i,res)))return -1;
        }
        return res;
    }
};
