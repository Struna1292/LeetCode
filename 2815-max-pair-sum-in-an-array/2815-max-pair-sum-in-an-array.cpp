class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        vector<int> biggests(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++)
        {
            string curr = to_string(nums[i]);
            int biggest = curr[0] - '0';
            for (int j = 0; j < curr.length(); j++)
            {
                if (curr[j] - '0' > biggest)
                {
                    biggest = curr[j] - '0';
                }
            }
            biggests[i] = biggest;
        }

        int output = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i != j && biggests[i] == biggests[j])
                {
                    if (nums[i] + nums[j] > output)
                        output = nums[i] + nums[j];
                }
            }
        }

        return output;
    }
};