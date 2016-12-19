class Solution {
public:
    void DSF(int num,vector<bool>&cur,int start,vector<string>&res){
        if(!num){
            int h=0,mit=0;
            for(int i=0;i<4;i++){
                if(cur[i])h+=pow(2,i);
            }
            for(int i=0;i<6;i++){
                if(cur[i+4])mit+=pow(2,i);
            }
            if(h>11||mit>59)return;
            if(mit<10)res.push_back(to_string(h)+":0"+to_string(mit));
            else res.push_back(to_string(h)+":"+to_string(mit));
            return;
        }
        //add to h
        for(int i=start;i<11-num;i++){
            cur[i]=true;
            DSF(num-1,cur,i+1,res);
            cur[i]=false;
        }
        return;
    }
    vector<string> readBinaryWatch(int num) {
        vector<string>res;
        vector<bool>cur(10,false);
        DSF(num,cur,0,res);
        return res;
    }
};
