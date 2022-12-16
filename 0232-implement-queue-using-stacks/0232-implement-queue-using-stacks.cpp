class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    
    
    MyQueue() {
        
    }
    
    void push(int val) {
        while(!st1.empty()){
            int x = st1.top();
            st1.pop();
            st2.push(x);
        }
        st2.push(val);
        while(!st2.empty()){
            int x = st2.top();
            st2.pop();
            st1.push(x);
        }
    }
    
    int pop() {
        int x = st1.top();
        st1.pop();
        return x;
    }
    
    int peek() {
        int ans = st1.top();
        return ans;
    }
    
    bool empty() {
        return st1.size() == 0;
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