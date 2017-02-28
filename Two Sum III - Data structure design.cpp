class TwoSum {
public:
    /** Initialize your data structure here. */
    TwoSum() {
        roc.clear();
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        roc[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        auto it=roc.begin();
        for(;it!=roc.end();it++){
            int t=value-it->first;
            if(t==it->first&&roc[t]>1)return true;
            if(t!=it->first&&roc.count(t))return true;
        }
        return false;
    }
    private:
    unordered_map<int,int>roc;
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */
