class Solution {
public:
    int hammingDistance(int x, int y) {
    int res=0;
    for(int i=0;i<31;i++){
        if((x>>i)^(y>>i))res++;
    }
    return res;

    }
};
