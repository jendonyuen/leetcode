class MinStack {
    int stack[8192];
    int *p = stack;
    int minStack[8192] = {INT_MAX};
    int *minP = minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        *p = x;
        p++;
        *(minP+1) = *minP < x ? *minP : x;
        minP++; 
    }
    
    void pop() {
        p--;
        minP--;
    }
    
    int top() {
        return *(p-1);
    }
    
    int getMin() {
        return *minP;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */