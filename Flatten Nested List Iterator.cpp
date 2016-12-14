class NestedIterator {
public:
queue<int>roc;
    NestedIterator(vector<NestedInteger> &nestedList) {
        DSF(roc,nestedList);
    }
    void DSF(queue<int>&roc,vector<NestedInteger>&cur){
        for(auto c:cur){
            if(c.isInteger())roc.push(c.getInteger());
            else DSF(roc,c.getList());
        }
        return;
    }

    int next() {
        int cur=roc.front();
        roc.pop();
        return cur;
    }

    bool hasNext() {
        return !roc.empty();
    }
};

