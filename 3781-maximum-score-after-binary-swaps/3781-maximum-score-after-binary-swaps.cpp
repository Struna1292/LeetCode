class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {

        long long output = 0;
        priority_queue<int> pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);

            if (s[i] == '1' && !pq.empty()) {
                output += pq.top();
                pq.pop();
            }
        }

        return output;
    }
};