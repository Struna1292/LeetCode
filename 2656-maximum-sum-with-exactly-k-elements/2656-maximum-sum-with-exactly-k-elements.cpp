class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int biggest = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > biggest)
                biggest = nums[i];
        }

        int output = biggest * k;

        for (int i = 1; i < k; i++)
        {
            output += i;
        }

        return output;
    }
};