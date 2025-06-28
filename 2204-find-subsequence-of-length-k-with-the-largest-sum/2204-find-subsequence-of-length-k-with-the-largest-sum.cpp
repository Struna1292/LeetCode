class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
        priority_queue<int> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push(nums[i]);
        }

        map<int,int> mp;

        while (!pq.empty() && k > 0) {
            mp[pq.top()]++;
            pq.pop();
            k--;
        }

        vector<int> output;

        for (int i = 0; i < nums.size(); i++) {
            if (mp[nums[i]] > 0) {
                output.push_back(nums[i]);
                mp[nums[i]]--;
            }
        }

        return output;
    }
};