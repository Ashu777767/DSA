class MyStack {
public:
   queue<int>q1;
    MyStack() {
        
    }
    
    void push(int x) {  //0(n)     //follow up using single queue
        q1.push(x);
        int size = q1.size();
        for(int i = 0;i<size-1;i++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {  //0(1)
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    
    int top() {   //0(1)
        return q1.front();
    }
    
    bool empty() {   //0(1)
        return q1.empty();
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