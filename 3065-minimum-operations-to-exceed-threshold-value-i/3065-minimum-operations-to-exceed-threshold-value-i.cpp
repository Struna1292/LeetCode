class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        sort(begin(nums), end(nums));

        if (nums[0] >= k)
        {
            return 0;
        }

        if (nums[nums.size()-1] < k)
        {
            return nums.size();
        }

        return lower_bound(begin(nums), end(nums), k) - begin(nums);
    }
};