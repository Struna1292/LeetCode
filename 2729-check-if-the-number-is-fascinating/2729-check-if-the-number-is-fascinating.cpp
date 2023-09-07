class Solution {
public:
    void helper(vector<int>& nums, int n)
    {
        while (n > 0)
        {
            nums[n%10]++;
            n /= 10;
        }
    }

    bool isFascinating(int n) {

        int second = n * 2;
        int third = n * 3;

        vector<int> nums(10, 0);

        helper(nums, n);
        helper(nums, second);
        helper(nums, third);

        for (int i = 1; i < 10; i++)
        {
            if (nums[i] != 1)
                return false;
        }

        return true;
    }
};