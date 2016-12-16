class Solution {
public:
    int head(int h){
        if(h<128)return 0;
        else if(h<192)return -1;
        else if(h<224)return 1;
        else if(h<240)return 2;
        else if(h<248)return 3;
        else return -1;
    }
    bool isbad(int a){
        return a<128||a>=192;
    }
    bool validUtf8(vector<int>& data) {
        int len=data.size();
        if(!len)return false;
        int cnt=0;
        for(int i=0;i<len;i++){
            if(!cnt){
                cnt=head(data[i]);
                if(cnt<0)return false;
            }
            else{
                if(isbad(data[i]))return false;
                cnt--;
            }
        }
        return !cnt;
    }
};
