class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        
        sort(begin(nums), end(nums));

        int prev = nums[0];
        int output = 0;
        int power = 0;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != prev)
            {
                power++;
                prev = nums[i];
            }
            output += power;
        }

        return output;
    }
};