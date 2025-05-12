class MinStack {
public:
    vector<long long> minimum;
    vector<long long> st;
    MinStack() {
        minimum.clear();
        st.clear();
    }
    
    void push(int val) {
        st.push_back(val);
        long long currElement = val;
        if (minimum.empty()) {
            minimum.push_back(currElement);
        }
        else {
            int minEle = minimum.back();
            minimum.push_back(min(val, minEle));
            
        }
    }
    
    void pop() {
        if (!st.empty()) {
            st.pop_back();
            minimum.pop_back();
        }
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return minimum.back();
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