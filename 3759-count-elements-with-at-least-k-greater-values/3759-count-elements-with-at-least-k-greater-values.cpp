class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int output = 0;

        for (int i = 0; i < nums.size(); i++) {
            int greaterElementsCount =  (end(nums) - upper_bound(begin(nums), end(nums), nums[i]));
            if (greaterElementsCount >= k) {
                output++;
            }
        }

        return output;
    }
};