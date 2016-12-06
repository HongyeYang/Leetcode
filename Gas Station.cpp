class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int diff=0,res=-1,acc=0;
        for(int i=0;i<gas.size();i++){
            diff=diff+gas[i]-cost[i];
            acc=acc+gas[i]-cost[i];
            if(diff>=0&&res==-1)res=i;
            if(diff<0){
                res=-1;
                diff=0;
            }
        }
        return acc>=0?res:-1;
    }
};
