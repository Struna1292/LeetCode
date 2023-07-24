class Solution {
public:
    int reductionOperations(vector<int>& nums) {

        sort(begin(nums), end(nums));

        int power = 0;
        int output = 0;
        int counter = 1;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != prev)
            {
                output += (counter * power);
                prev = nums[i];
                counter = 1;
                power++;
            }
            else
            {
                counter++;
            }
        }
        output += (counter * power);

        return output;
    }
};