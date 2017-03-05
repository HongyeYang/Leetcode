class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        string s;
        for(string &st:sentence){
            s+=st;
            s.push_back(' ');
        }
        int start=0;
        int l=s.size();
        for(int i=0;i<rows;i++){
            start+=cols;
            if(s[start%l]==' ')start++;
            else{
                while(start>0&&s[(start-1)%l]!=' ')start--;
            }
        }
        return start/l;
    }
};
