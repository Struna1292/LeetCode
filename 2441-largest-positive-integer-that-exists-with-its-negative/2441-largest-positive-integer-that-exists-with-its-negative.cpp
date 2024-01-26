class Solution {
public:
    bool binarySearch(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
            {
                return true;
            }
            if (target > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }

    int findMaxK(vector<int>& nums) {
        
        sort(begin(nums), end(nums));

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                if(binarySearch(nums, nums[i]*-1))
                {
                    return nums[i] * -1;
                }
            }
            else
            {
                break;
            }
        }

        return -1;
    }
};