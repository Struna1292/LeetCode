class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int counter = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                counter++;
                for (int j = i+1; j < nums.size(); j++)
                {
                    nums[j] -= nums[i];
                }
                nums[i] = 0;
            }
        }

        return counter;
    }
};