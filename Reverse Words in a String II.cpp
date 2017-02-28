class Solution {
public:
    void reverseWords(string &s) {
        auto pre=s.begin();
        auto post=s.begin();
        for(;post!=s.end();post++){
            if(*post==' '){
                reverse(pre,post);
                post++;
                pre=post;
            }
        }
        reverse(pre,post);
        reverse(s.begin(),s.end());
        return;
    }
};
