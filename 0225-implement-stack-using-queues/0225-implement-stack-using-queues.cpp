class MyStack {
public:
    queue< int > qu;
    MyStack() {
        
    }
    
    void push(int x) {
        qu.push(x);
    }   
    
    int pop() {
        int size = qu.size();
        while(size > 1){
            int top = qu.front();
            qu.pop();
            qu.push(top);
            size--;
        }
        int ele = qu.front();
        qu.pop();
        return ele;
    }
    
    int top() {
        int size = qu.size();
        int top = 0;
        while(size > 0){
            top = qu.front();
            qu.pop();
            qu.push(top);
            size--;
        }
        return top;
    }
    
    bool empty() {
        return qu.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */