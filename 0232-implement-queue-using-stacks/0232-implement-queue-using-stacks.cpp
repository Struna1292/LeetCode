class MyQueue {
public:

    struct element {
        int val;
        element* next;
    };

    element* head;
    element* tail;

    MyQueue() {
        head = nullptr;
        tail = nullptr;
    }
    
    void push(int x) {
        element *el = new element;
        el->val = x;
        el->next = nullptr;
        if (tail == NULL)
        {
            head = el;
        }
        else
        {
            tail->next = el;
        }
        tail = el;
    }
    
    int pop() {
        int num = NULL;
        if (head != NULL)
        {
            num = head->val;
        }
        element *temp = head;
        head = head->next;
        delete temp;
        if (head == NULL)
        {
            tail = NULL;
        }
        return num;
    }
    
    int peek() {
        if (head != NULL)
        {
            return head->val;
        }
        else
        {
            return NULL;
        }
    }
    
    bool empty() {
        if (head == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */