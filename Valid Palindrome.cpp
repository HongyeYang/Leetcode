class Solution {
public:
    bool isPalindrome(string s) {
        int len=s.size();
        if(!len)return true;
        int left=0,right=len-1,trans=abs('A'-'a');
        while(left<right){
            while(left<len&&(s[left]<'a'||s[left]>'z')&&(s[left]<'A'||s[left]>'Z')&&(s[left]>'9'||s[left]<'0'))left++;
            while(right>=0&&(s[right]<'a'||s[right]>'z')&&(s[right]<'A'||s[right]>'Z')&&(s[right]>'9'||s[right]<'0'))right--;
            if(left==len||right==-1)break;
            if(s[left]>='0'&&s[left]<='9'){
                if(s[left]!=s[right])return false;
            }
            else if(s[left]!=s[right]&&(abs(s[left]-s[right])!=trans))return false;
            left++;
            right--;
        }
        return true;
    }
};
