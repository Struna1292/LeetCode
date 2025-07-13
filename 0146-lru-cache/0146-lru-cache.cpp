class LRUCache {
public:
    list<pair<int,int>> ll;
    int length;
    int size;
    unordered_map<int, list<pair<int,int>>::iterator> mp;

    LRUCache(int capacity) {
        size = capacity;
        length = 0;
    }

    void printLL() {
        for (auto itr = ll.begin(); itr != ll.end(); itr++) {
            cout << "key: " << itr->first << " val: " << itr->second << " ";
        }
        cout << endl;
    }

    int get(int key) {
        auto itr = mp.find(key);

        if (itr == mp.end()) {
            return -1;
        }

        int value = mp[key]->second;

        auto itr2 = mp[key];
        mp.erase(itr);
        ll.erase(itr2);

        ll.push_front({key, value});
        mp[key] = ll.begin();

        return value;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            get(key);
            ll.begin()->second = value;
            return;
        }

        ll.push_front({key, value});
        mp[key] = ll.begin();
        length++;

        if (length > size) {
            pair<int,int> last = ll.back();
            mp.erase(mp.find(last.first));
            ll.pop_back();
            length--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */