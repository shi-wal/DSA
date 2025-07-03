class MyQueue {
    stack<int> s1, s2;
public:
  // O(1)
    void push(int x) {
        s1.push(x);
    }

  // amortised O(1)
    int pop() {
        if(s2.empty()){  // REVISE
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x=s2.top();
        s2.pop();
        return x;
    }

  // amortised O(1)
    int peek() {
        if(s2.empty()){   // REVISE
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
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
