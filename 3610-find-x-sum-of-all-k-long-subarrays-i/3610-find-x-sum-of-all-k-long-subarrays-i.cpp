class Solution {
public:
    struct Item {
        int occurrences;
        int value;
        Item(int o, int v) {
            occurrences = o;
            value = v;
        }
    };

    struct Comparator {
        bool operator()(Item& a, Item& b) {
            if (a.occurrences == b.occurrences) {
                return a.value > b.value;
            }

            return a.occurrences > b.occurrences;
        }
    };

    vector<int> findXSum(vector<int>& nums, int k, int x) {
        
        unordered_map<int, int> um;

        vector<int> output;

        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;

            if (i+1 >= k) {
                if (i+1 != k) {
                    um[nums[i-k]]--;
                }

                priority_queue<Item, vector<Item>, Comparator> pq; // min heap

                for (auto itr = um.begin(); itr != um.end(); itr++) {
                    if (pq.size() < x) {
                        pq.push(Item(itr->second, itr->first));
                    }
                    else if (pq.top().occurrences < itr->second || (pq.top().occurrences == itr->second && pq.top().value < itr->first)) {
                        pq.pop();
                        pq.push(Item(itr->second, itr->first));
                    }
                }

                int currSum = 0;
                while (!pq.empty()) {
                    Item curr = pq.top();
                    pq.pop();

                    currSum += (curr.occurrences * curr.value);
                }

                output.push_back(currSum);
            }
        }

        return output;
    }
};