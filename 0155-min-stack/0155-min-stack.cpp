class MinStack {
public:

    struct element {
        int val;
        element* next;
    };

    element* head;

    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        element *el = new element;
        el->val = val;
        el->next = head;
        head = el;
    }
    
    void pop() {
        element* temp = head;
        head = head->next;
        delete temp;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        element* curr = head;
        int min = curr->val;
        while (curr != NULL)
        {
            if (min > curr->val)
            {
                min = curr->val;
            }
            curr = curr->next;
        }
        return min;
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