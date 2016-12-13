class Solution {
public:
    bool isValidSerialization(string preorder) {
        int comma=0,sign=0;
        for(char c:preorder){
            if(c==','){
                comma++;
                if(2*sign>=comma+1)return false;
            }
            else if(c=='#')sign++;
        }
        return sign*2==comma+2;
    }
};
