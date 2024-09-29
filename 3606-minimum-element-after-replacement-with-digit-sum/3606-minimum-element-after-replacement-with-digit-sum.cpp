class Solution {
public:
    int minElement(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++)
        {
            string curr = to_string(nums[i]);

            nums[i] = 0;

            for (int j = 0; j < curr.length(); j++)
            {
                nums[i] += curr[j] - '0';
            }
        }

        int output = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] < output)
            {
                output = nums[i];
            }
        }

        return output;
    }
};