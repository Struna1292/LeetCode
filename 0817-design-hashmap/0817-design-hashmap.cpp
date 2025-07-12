class MyHashMap {
public:
    struct LLnode { // linked list node
        int key;
        int value;
        LLnode* next;
        LLnode(int k, int v) {
            key = k;
            value = v;
            next = nullptr;
        }
    };

    LLnode** array;
    int length;
    int capacity;
    float loadFactor;

    void arrayInitHelper() {
        for (int i = 0; i < capacity; i++) {
            array[i] = nullptr;
        }
    }

    MyHashMap() {
        length = 0;
        capacity = 4;
        loadFactor = 0.75;
        array = new LLnode*[capacity];
        arrayInitHelper();
    }

    void resizeHelper(LLnode* curr) {
        if (curr == nullptr) {
            return;
        }

        resizeHelper(curr->next);

        put(curr->key, curr->value);

        delete curr;
    }
    
    void put(int key, int value) {
        hash<int> h;
        int idx = h(key) % capacity;

        // insert
        if (array[idx] == nullptr) {
            array[idx] = new LLnode(key, value);
        } else {
            LLnode* curr = array[idx];
            // iterate through linked list until we reach last node or they key already exists and update value
            while (curr->next != nullptr && curr->key != key) {
                curr = curr->next;
            }

            if (curr->key == key) {
                curr->value = value;
            } else {
                curr->next = new LLnode(key, value);
            }
        }
        length++;

        //check load factor and resize if needed
        if (loadFactor < static_cast<float>(length) / static_cast<float>(capacity)) {
            LLnode** temp = array;
            int oldCapacity = capacity;
            array = nullptr;

            capacity *= 2;
            length = 0;
            array = new LLnode*[capacity];
            arrayInitHelper();

            for (int i = 0; i < oldCapacity; i++) {
                if (temp[i] != nullptr) {
                    resizeHelper(temp[i]);
                    temp[i] = nullptr;
                }
            }
            delete[] temp;
        }
    }
    
    int get(int key) {
        hash<int> h;
        int idx = h(key) % capacity;

        if (array[idx] != nullptr) {
            LLnode* curr = array[idx];

            while (curr != nullptr) {
                if (curr->key == key) {
                    return curr->value;
                }
                curr = curr->next;
            }
        }

        return -1;
    }
    
    void remove(int key) {
        hash<int> h;
        int idx = h(key) % capacity;

        if (array[idx] != nullptr) {
            LLnode* curr = array[idx];

            // removal node is first element
            if (curr->key == key) {
                if (curr->next == nullptr) {
                    array[idx] = nullptr;
                } else {
                    array[idx] = curr->next;
                }
                delete curr;

                length--;
                return;
            }

            // removal node is inside or last element
            LLnode* prev = curr;
            curr = curr->next;
            while (curr != nullptr) {
                if (curr->key == key) {
                    prev->next = curr->next;
                    delete curr;
                    length--;
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
        }
    }

    void removeHelper(LLnode* curr) {
        if (curr == nullptr) {
            return;
        }

        removeHelper(curr->next);

        delete curr;
    }

    ~MyHashMap() {

        for (int i = 0; i < capacity; i++) {
            if (array[i] == nullptr) {
                removeHelper(array[i]);
                array[i] = nullptr;
            }
        }

        delete[] array;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */