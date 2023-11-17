class Solution {
public:
    int minPairSum(vector<int>& nums) {

        sort(begin(nums), end(nums));

        int output = 0;

        int i = 0;
        int j = nums.size()-1;

        while (i < j)
        {
            if (nums[i] + nums[j] > output)
            {
                output = nums[i] + nums[j];
            }
            i++;
            j--;
        }

        return output;
    }
};