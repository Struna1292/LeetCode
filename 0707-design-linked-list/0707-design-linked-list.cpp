class MyLinkedList {
public:

    struct Node
    {
        int val;
        Node* next;
    };

    Node* head;

    MyLinkedList() {
        head = nullptr;
    }
    
    int get(int index) {
        int num = -1;
        Node* curr = head;
        int i = 0;
        while (curr != NULL)
        {
            if (i == index)
            {
                num = curr->val;
                break;
            }
            i++;
            curr = curr->next;
        }
        return num;
    }
    
    void addAtHead(int val) {
        Node* temp = new Node;
        temp->val = val;
        temp->next = head;
        head = temp;
    }
    
    void addAtTail(int val) {
        if (head == NULL)
        {
            addAtHead(val);
            return;
        }
        Node* curr = head;
        while (curr != NULL)
        {
            if (curr->next == NULL)
            {
                curr->next = new Node;
                curr = curr->next;
                curr->val = val;
                curr->next = nullptr;
            }
            curr = curr->next;
        }
    }
    
    void addAtIndex(int index, int val) {
        if (index == 0)
        {
            addAtHead(val);
        }
        else
        {
            int i = 1;
            Node* curr = head;
            Node* curr1;
            while (curr != NULL)
            {
                if (i == index)
                {
                    Node* temp = new Node;
                    temp->val = val;
                    temp->next = curr->next;
                    curr->next = temp;
                    break;
                }
                curr = curr->next;
                i++;
            }
        }
    }
    
    void deleteAtIndex(int index) {
        if (index == 0)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        else
        {
            int i = 0;
            Node* curr = head;
            Node* prev;
            while (curr != NULL)
            {
                if (i == index)
                {
                    prev->next = curr->next;
                    delete curr;
                    break;
                }
                prev = curr;
                curr = curr->next;
                i++;
            }
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */