class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // min heap

        for (auto itr = mp.begin(); itr != mp.end(); itr++) {
            if (pq.size() < k) {
                pq.push({itr->second, itr->first});
            } else if (pq.top().first < itr->second) {
                pq.pop();
                pq.push({itr->second, itr->first});
            }
        }

        vector<int> output;

        while (!pq.empty()) {
            output.push_back(pq.top().second);
            pq.pop();
        }

        return output;
    }
};