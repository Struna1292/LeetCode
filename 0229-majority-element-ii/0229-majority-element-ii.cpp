class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int counter = 0;
        int prev = nums[0];

        vector<int> output;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == prev) {
                counter++;
            }
            else {
                if (counter > nums.size() / 3) {
                    output.push_back(prev);
                }

                counter = 1;
            }
            prev = nums[i];
        }
        if (counter > nums.size() / 3) {
            output.push_back(prev);
        }

        return output;
    }
};