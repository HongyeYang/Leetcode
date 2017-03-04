class Logger {
public:
    /** Initialize your data structure here. */
    Logger() {
        roc.clear();
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if(roc.count(message)&&timestamp-roc[message]<10)return false;
        roc[message]=timestamp;
        return true;
    }
private:
unordered_map<string,int>roc;
};
