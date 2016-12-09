class MinStack {
private:
stack<int>roc;
stack<int>s;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(roc.empty()||roc.top()>=x){
            roc.push(x);
        }
        return;
    }
    
    void pop() {
        if(roc.top()==s.top())roc.pop();
        s.pop();
        return;
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return roc.top();
    }
};

