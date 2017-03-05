class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        m=maxNumbers;
        for(int i=0;i<m;i++)available.insert(i);
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if(available.empty())return -1;
        int r=*available.begin();
        available.erase(available.begin());
        return r;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return available.count(number)>0;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        available.insert(number);
    }
    private:
    int m;
    unordered_set<int>available;
};
