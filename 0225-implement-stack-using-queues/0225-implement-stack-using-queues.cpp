class MyStack {
public:
    queue<int>q,t;
    MyStack() {
        
    }
    
    void push(int x) {
       t.push(x); 
       while(!q.empty()){
        t.push(q.front());
        q.pop();
       }
       swap(q,t);
    }
    
    int pop() {
       int x = q.front();
        q.pop();

        return x;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */