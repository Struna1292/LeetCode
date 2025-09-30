class Solution {
public:
    int triangularSum(vector<int>& nums) {
        
        queue<int> q;

        for (int i = 0; i < nums.size(); i++) {
            q.push(nums[i]);
        }

        while (q.size() > 1) {
            
            int currLevel = q.size();
            for (int i = 0; i < currLevel-1; i++) {
                int curr = q.front();
                q.pop();

                q.push((curr + q.front()) % 10);
            }
            // skip last one beacuse we look forward
            q.pop();
        }

        return q.front();
    }
};