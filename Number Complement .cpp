class Solution {
public:
    int findComplement(int num) {
        int mask=1;
        int i=1;
        while(mask<num){
            mask|=(1<<i++);
        }
        return mask^num;
    }
};
