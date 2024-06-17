class Solution {
public:
    bool judgeSquareSum(int c) {

        if (c == 0)
        {
            return true;
        }

        vector<long> nums;

        long i = 0;

        while (i*i <= c)
        {
            nums.push_back(i*i);
            i++;
        }

        i = 0;
        int j = nums.size()-1;


        while (i < j)
        {
            if (nums[i] + nums[i] == c || nums[j] + nums[j] == c)
            {
                return true;
            }
            else if (nums[i] + nums[j] > c)
            {
                j--;
            }
            else if (nums[i] + nums[j] < c)
            {
                i++;
            }
            else
            {
                return true;
            }
        }

        return false;
    }
};