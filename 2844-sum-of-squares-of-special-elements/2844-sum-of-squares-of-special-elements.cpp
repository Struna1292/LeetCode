class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        
        int output = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums.size() % (i+1) == 0)
            {
                output += nums[i] * nums[i];
            }
        }

        return output;
    }
};