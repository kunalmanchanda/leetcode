class MinStack {
public:
   stack<int> s, min;
    MinStack() {

    }
    
    void push(int val) {
        s.push(val);
        if(!min.empty() && min.top() >= val) {
            min.push(val);
        } else if(min.empty()) {
             min.push(val);
        }
    }
    
    void pop() {
        int ele = s.top();
        s.pop();
        if(ele == min.top()) {
            min.pop();
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */