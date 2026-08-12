class MinStack {
public:
    stack<int> st;
    stack<int> min;

    MinStack() {
        min.push(INT_MAX);
    }
    
    void push(int value) {
        st.push(value);
        if(min.top()>=value){
            min.push(value);
        }
    }
    
    void pop() {
        if(min.top()==st.top()){
        min.pop();}
        st.pop();
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */