class MyStack {
public:
    queue<int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int> temp;
        int n = q.size();
        for (int i = 1; i < n; i++)
        {
            temp.push(q.front());
            q.pop();
        }
        int output = q.front();
        q = temp;
        return output;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        if (q.empty())
            return true;
        return false;
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