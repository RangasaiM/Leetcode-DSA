class MyQueue {
public:
    stack<int> a;
    stack<int> b;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!a.empty()){
            int t=a.top();
            a.pop();
            b.push(t);
        }
        b.push(x);
        while(!b.empty()){
            int t=b.top();
            b.pop();
            a.push(t);
        }
        
    }
    
    int pop() {
        int t=a.top();
        a.pop();
        return t;
    }
    
    int peek() {
        return a.top();
    }
    
    bool empty() {
        return a.empty();
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