class MyQueue {
public:
    stack<int>st;
    stack<int>gt;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        if (gt.empty()) {
            while (!st.empty()) {
                gt.push(st.top());
                st.pop();
            }
        }
        int x = gt.top();
        gt.pop();
        return x;
    }
    
    int peek() {
        if (gt.empty()) {
            while (!st.empty()) {
                gt.push(st.top());
                st.pop();
            }
        }
        return gt.top();
    
    }
    
    bool empty() {
        return st.empty() && gt.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */