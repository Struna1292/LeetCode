class Solution {
public:
    struct Comparator {
        bool operator()(int& a, int& b) {
            return a > b;
        }
    };

    vector<int> maxKDistinct(vector<int>& nums, int k) {
        
        priority_queue<int, vector<int>, Comparator> pq;
        unordered_map<int, int> um;

        for (int i = 0; i < nums.size(); i++) {
            um[nums[i]]++;
            if (pq.size() < k && um[nums[i]] == 1) {
                pq.push(nums[i]);
            }
            else if (um[nums[i]] == 1 && pq.top() < nums[i]) {
                pq.pop();
                pq.push(nums[i]);
            }
        }

        vector<int> output(pq.size(), 0);
        int i = pq.size()-1;
        while (!pq.empty()) {
            output[i] = pq.top();
            pq.pop();
            i--;
        }

        return output;
    }
};