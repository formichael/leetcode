class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);

        int minVal = val;
        if (!minSt.empty() && minVal > minSt.top()) {
            minVal = minSt.top();
        }
        minSt.push(minVal);
    }
    
    void pop() {
        if (!st.empty())
            st.pop();
        
        if (!minSt.empty())
            minSt.pop();
    }
    
    int top() {
        assert(!st.empty());
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }

private:
    stack<int> st;
    stack<int> minSt;    
};
