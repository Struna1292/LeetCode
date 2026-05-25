class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> output;

        int counter = 1;
        int prev = nums[0];
        output.push_back(prev);
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == prev) {
                if (counter < k) {
                    counter++;
                    output.push_back(nums[i]);
                }
            }
            else {
                prev = nums[i];
                counter = 1;
                output.push_back(prev);
            }
        }

        return output;
    }
};