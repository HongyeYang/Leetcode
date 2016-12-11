class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int len=nums.size();
        if(!len)return {};
        int n1=0,n2=0,c1=0,c2=0;
        for(int c:nums){
            if(c==n1)c1++;
            else if(c==n2)c2++;
            else if(c1==0){n1=c;c1++;}
            else if(c2==0){n2=c;c2++;}
            else {c1--;c2--;}
        }
        c1=0;c2=0;
        for(int c:nums){
            if(c==n1)c1++;
            else if(c==n2)c2++;
        }
        vector<int>res;
        if(c1>len/3)res.push_back(n1);
        if(c2>len/3)res.push_back(n2);
        return res;
    }
};
