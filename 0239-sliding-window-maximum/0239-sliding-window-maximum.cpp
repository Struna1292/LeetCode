class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>> pq; // max heap   pair<value, index>
        vector<int> maxValues(nums.size()-k+1, 0);

        for (int i = 0; i < k-1; i++) {
            pq.push({nums[i], i});
        }

        for (int i = k-1; i < nums.size(); i++) {
            pq.push({nums[i], i});
            
            // check if this value is still in the range if not pop
            while (i - pq.top().second >= k) { 
                pq.pop();
            }

            maxValues[i-(k-1)] = pq.top().first;
        }

        return maxValues;
    }
};