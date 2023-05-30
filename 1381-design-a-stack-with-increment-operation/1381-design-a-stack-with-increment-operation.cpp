class CustomStack {
public:

    struct node {
        int val;
        node* next = nullptr;
    };

    int currentSize = 0;
    int maxSize = 0;
    node* head;

    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        head = nullptr;
    }

    void push(int x) {
        if (currentSize != maxSize)
        {
            currentSize++;
            if (head == nullptr)
            {
                head = new node;
                head->val = x;
            }
            else
            {
                node* temp = new node;
                temp->val = x;
                temp->next = head;
                head = temp;
            }
        }
    }

    int pop() {
        if (head == nullptr)
        {
            return -1;
        }
        else
        {
            currentSize--;
            node* temp = head;
            int num = head->val;
            head = head->next;
            delete temp;
            return num;
        }
    }

    void increment(int k, int val) {
        node* curr = head;
        int skip = currentSize - k;


        while (curr != NULL)
        {
            if (skip > 0)
            {
                skip--;
            }
            else
            {
                curr->val = curr->val + val;
            }
            curr = curr->next;
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