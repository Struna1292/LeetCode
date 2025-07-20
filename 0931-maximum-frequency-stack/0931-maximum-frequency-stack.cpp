class FreqStack {
public:
    struct node {
        int frequency;
        int pushTime;
        int value;
        node(int f, int pT, int v) {
            frequency = f;
            pushTime = pT;
            value = v;
        }
    };

    struct comparator {
        bool operator()(node& a, node& b) {
            if (a.frequency < b.frequency || (a.frequency == b.frequency && a.pushTime < b.pushTime)) {
                return true;
            }

            return false;
        }
    };

    // use max freq heap 
    // when pushing add 
    priority_queue<node, vector<node>, comparator> pq;
    unordered_map<int, int> um; // value, frequency
    int time;

    FreqStack() {
        time = 0;
    }
    
    void push(int val) {
        um[val]++;
        pq.push(node(um[val], time, val));
        time++;
    }
    
    int pop() {
        node curr = pq.top();
        pq.pop();
        um[curr.value]--;

        return curr.value;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */