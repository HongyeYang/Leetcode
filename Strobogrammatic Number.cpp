class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char,char>pairs;
        pairs['0']='0';
        pairs['1']='1';
        pairs['6']='9';
        pairs['9']='6';
        pairs['8']='8';
        
        int left=0,right=num.size()-1;
        while(left<=right){
            if(num[left++]!=pairs[num[right--]])return false;
        }
        return true;
    }
};
