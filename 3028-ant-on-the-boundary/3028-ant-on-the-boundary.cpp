class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int currPosition = 0;

        int output = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            currPosition += nums[i];
            if (currPosition == 0)
            {
                output++;
            }
        }

        return output;
    }
};