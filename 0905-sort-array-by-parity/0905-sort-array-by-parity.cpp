class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j)
        {
            if (nums[i] % 2 != 0)
            {
                while (nums[j] % 2 != 0 && i < j)
                {
                    j--;
                }
                swap(nums[i],nums[j]);
            }
            i++;
        }
        return nums;
    }
};