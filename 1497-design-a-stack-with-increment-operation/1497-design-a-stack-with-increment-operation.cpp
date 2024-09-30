class CustomStack {
public:
    struct Node
    {
        int val = 0;
        Node* next = nullptr;
    };

    int currSize = 0;
    int size = 0;
    Node* head = nullptr;

    CustomStack(int maxSize) {
        size = maxSize;
    }
    
    void push(int x) {
        if (currSize < size)
        {
            currSize++;

            if (head == nullptr)
            {
                head = new Node;
                head->val = x;
            }
            else
            {
                Node* temp = new Node;
                temp->val = x;
                temp->next = head;
                head = temp;
            }
        }
    }
    
    int pop() {
        if (head != nullptr)
        {
            currSize--;
            int value = head->val;
            Node* temp = head;
            head = head->next;
            delete temp;
            return value;
        }

        return -1;
    }
    
    void increment(int k, int val) {
        if (currSize <= k)
        {
            Node* curr = head;

            while (curr != nullptr)
            {
                curr->val += val;
                curr = curr->next;
            }
        }
        else
        {
            int skip = currSize - k;
            Node* curr = head;

            while (skip > 0)
            {
                skip--;
                curr = curr->next;
            }

            while (curr != nullptr)
            {
                curr->val += val;
                curr = curr->next;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */