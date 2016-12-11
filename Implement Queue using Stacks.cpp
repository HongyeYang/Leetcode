class Queue {
public:
    stack<int>s1;
    stack<int>s2;
    // Push element x to the back of queue.
    void push(int x) {
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
            s2.push(x);
            while(!s2.empty()){
                s1.push(s2.top());
                s2.pop();
            }
        return;
    }

    // Removes the element from in front of queue.
    void pop(void) {
        s1.pop();
        return;
    }

    // Get the front element.
    int peek(void) {
        return s1.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return s1.empty();
    }
};
