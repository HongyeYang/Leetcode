class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        priority_queue<int>doable;
        multiset<pair<int,int>>undoable;
        for(int i=0;i<Profits.size();i++){
            if(Profits[i]){
                if(Capital[i]<=W)doable.push(Profits[i]);
                else undoable.insert({Capital[i],Profits[i]});
            }
        }
        while(k--&&doable.size()){
            W+=doable.top();
            doable.pop();
            while(undoable.size()&&undoable.begin()->first<=W){
                doable.push(undoable.begin()->second);
                undoable.erase(undoable.begin());
            }
        }
        
        return W;
    }
};
