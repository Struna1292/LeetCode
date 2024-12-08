class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        sort(begin(nums), end(nums));

        nums.erase(unique(begin(nums), end(nums)), end(nums));

        int i = 0;
        if (nums[i] == k)
        {
            i++;
        }
        else if (nums[i] < k)
        {
            return -1;
        }

        return nums.size()-i;
    }
};