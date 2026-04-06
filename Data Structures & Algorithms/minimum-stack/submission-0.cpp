class MinStack {
public:
    stack<int> st;
    vector<int> res;
    MinStack() {}

    void push(int val) {
        st.push(val);

        if(res.empty()) res.push_back(val);
        else
        {
            res.push_back(min(val,res.back()));
        }
    }

    void pop() {
        st.pop();
        res.pop_back();
    }

    int top() { return st.top(); }

    int getMin() {
        return res.back();
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