class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        
        sort(begin(nums), end(nums));

        vector<vector<int>> output;

        for (int i = 0; i < nums.size(); i+=3) {
            vector<int> curr;
            int prev = nums[i];
            for (int j = i; j < i+3; j++) {
                if (nums[j] - prev > k) {
                    return {};
                }
                curr.push_back(nums[j]);
            }

            output.push_back(curr);
        }

        return output;
    }
};