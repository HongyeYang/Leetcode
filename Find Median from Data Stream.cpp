class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        mn.push(num);
        mx.push(-mn.top());
        mn.pop();
        if(mn.size()<mx.size()){
            mn.push(-mx.top());
            mx.pop();
        }
    }
    
    double findMedian() {
        if(mx.size()==mn.size())return (mn.top()-mx.top())/2.0;
        else return mn.top();
    }
private:
priority_queue<int,vector<int>>mx,mn;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
