class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
    
        sort(begin(nums), end(nums));
        int output = nums.size()-1;

        for (int i = 0; i < nums.size(); i++) {
            long long curr = nums[i] * (long long)k;

            int j = upper_bound(begin(nums), end(nums), curr) - begin(nums);

            if (i + nums.size() - j < output) {
                output = i + nums.size() - j;
            }
        }

        return output;
    }
};