class Solution {
public:
    int minimumSum(vector<int>& nums) {
        
        vector<int> minLeft(nums.size(), 0);
        vector<int> minRight(nums.size(), 0);


        int i = 0;
        int j = nums.size()-1;

        int currMinLeft = nums[i];
        int currMinRight = nums[j];

        while (i < nums.size())
        {
            if (nums[i] < currMinLeft)
            {
                currMinLeft = nums[i];
            }

            if (nums[j] < currMinRight)
            {
                currMinRight = nums[j];
            }

            minLeft[i] = currMinLeft;
            minRight[j] = currMinRight;

            i++;
            j--;
        }


        int output = -1;

        for (int i = 1; i < nums.size()-1; i++)
        {
            if (nums[i] > minLeft[i] && nums[i] > minRight[i])
            {
                if (output == -1 || output > nums[i] + minLeft[i] + minRight[i])
                {
                    output = nums[i] + minLeft[i] + minRight[i];
                }
            }
        }
        
        return output;
    }
};