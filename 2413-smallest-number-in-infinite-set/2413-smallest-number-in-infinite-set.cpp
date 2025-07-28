class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    unordered_set<int> us; // contains values that are not present

    SmallestInfiniteSet() {
        pq.push(1);
    }
    
    int popSmallest() {
        int smallest = pq.top();
        pq.pop();

        if (pq.empty()) {
            pq.push(smallest+1);
        }

        us.insert(smallest);
        return smallest;
    }
    
    void addBack(int num) {
        auto itr = us.find(num);
        if (itr != us.end()) { // value is not present in infinite set so we can add it 
            us.erase(itr);
            pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */