class Solution {
public:
    int binarySearch(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return mid;
            }

            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;
    }

    int firstMissingPositive(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int index = binarySearch(nums, 1);

        if (index == -1)
        {
            return 1;
        }
        
        for (int i = index; i < nums.size()-1; i++)
        {
            if (nums[i]+1 != nums[i+1] && nums[i] != nums[i+1])
            {
                return nums[i]+1;
            }
        }

        return nums[nums.size()-1]+1;
    }
};