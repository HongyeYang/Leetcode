class Solution {
public:
    int findMinStep(string board, string hand) {
        sort(hand.begin(),hand.end());
        int res= dfs(board,hand);
        return res>hand.size()?-1:res;
    }
    int dfs(string board,string hand){
        if(board.size()==0)return 0;
        if(hand.size()==0)return 6;
        int res=6;
        for(int i=0;i<hand.size();i++){
            int j=0;
            while(j<board.size()){
                int k=board.find(hand[i],j);
                if(k==string::npos)break;
                if(k<board.size()-1&&board[k]==board[k+1]){
                    string nextb=shrink(board.substr(0,k)+board.substr(k+2));
                    if(nextb.empty())return 1;
                    string nexth=hand;
                    nexth.erase(i,1);
                    res=min(res,dfs(nextb,nexth)+1);
                    k++;
                }
                else if(i>0&&hand[i]==hand[i-1]){
                    string nextb=shrink(board.substr(0,k)+board.substr(k+1));
                    if(nextb.empty())return 2;
                    string nexth=hand;
                    nexth.erase(i,1);
                    nexth.erase(i-1,1);
                    res=min(res,dfs(nextb,nexth)+2);
                }
                j=k+1;
            }
        }
        return res;
    }
    string shrink(string s){
        while(s.size()){
            bool done=true;
            for(int i=0;i<s.size()-1;i++){
                int j=i+1;
                while(j<s.size()&&s[j]==s[j-1])j++;
                if(j-i>2){
                    done=false;
                    s=s.substr(0,i)+s.substr(j);
                    break;
                }
            }
            if(done)break;
        }
        return s;
    }
};
