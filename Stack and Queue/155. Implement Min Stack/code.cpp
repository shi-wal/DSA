class MinStack {
    long long mini=INT_MAX;
    stack<long long> st;
public:
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini=val;
        }
        else{
            if(val<mini){
                long long new_val=2*(long long)val-mini;
                st.push(new_val);
                mini=val;
            }
            else st.push(val);
        }
    }
    
    void pop() {
        if(st.empty()) return;
        if(st.top()<mini){
            mini=2*mini-st.top();
        }
        st.pop();
    }
    
    int top() {
        if(st.empty()) return -1;
        if(st.top()<mini) return (int)mini;
        return (int)st.top();
    }
    
    int getMin() {
        return (int)mini;
    }
};
