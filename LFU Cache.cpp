class LFUCache {
public:
    LFUCache(int capacity) {
        cap=capacity;
        minfreq=1;
        size=0;
    }
    
    int get(int key) {
        if(!roc.count(key))return -1;
        int curfreq=roc[key].second;
        freq[curfreq].erase(iter[key]);
        if(freq[minfreq].size()==0)minfreq++;
        curfreq++;
        freq[curfreq].push_back(key);
        iter[key]=--freq[curfreq].end();
        roc[key].second=curfreq;
        return roc[key].first;
    }
    
    void put(int key, int value) {
        if(cap<=0)return;
        int last=get(key);
        if(last==-1){
            if(size>=cap){
                int erskey=freq[minfreq].front();
                freq[minfreq].pop_front();
                roc.erase(erskey);
                iter.erase(erskey);
                size--;
            }
            minfreq=1;
            roc[key]={value,1};
            freq[1].push_back(key);
            iter[key]=--freq[1].end();
            size++;
            return;
        }
        else{
            roc[key].first=value;
            return;
        }
        
    }
    
private:
    //<key,pair<value,freq>>
    unordered_map<int,pair<int,int>>roc;
    
    //<freq,list<key>>
    unordered_map<int,list<int>>freq;
    
    //<key,list::interator>
    unordered_map<int,list<int>::iterator>iter;
    
    int size;
    int minfreq;
    int cap;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
