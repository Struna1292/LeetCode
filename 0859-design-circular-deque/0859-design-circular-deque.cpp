class MyCircularDeque {
public:
    int maxSize;
    list<int> list;

    MyCircularDeque(int k) {
        maxSize = k;
    }
    
    bool insertFront(int value) {
        if (list.size() < maxSize) {
            list.push_front(value);
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if (list.size() < maxSize) {
            list.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if (list.size() > 0) {
            list.pop_front();
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if (list.size() > 0) {
            list.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        if (list.size() > 0) {
            return list.front();
        }
        return -1;
    }
    
    int getRear() {
        if (list.size() > 0) {
            return list.back();
        }
        return -1;
    }
    
    bool isEmpty() {
        return list.size() == 0;
    }
    
    bool isFull() {
        return list.size() == maxSize;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */