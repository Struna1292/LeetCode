class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        else if (nums.size() == 2)
        {
            if (nums[0] > nums[1])
                return nums[1];
            else
                return nums[0];
        }

        int left = 0;
        int right = nums.size()-1;

        while (left <= right)
        {
            if (left+1 == right)
            {
                if (nums[left] > nums[right])
                    return nums[right];
                else
                    return nums[left];
            }
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[right])
                return nums[left];
            if (nums[mid] < nums[mid-1]) 
            {
                return nums[mid];
            }

            if (nums[mid] < nums[left])
            {
                if (nums[left] > nums[right])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else // nums[mid] > nums[left]
            {
                if (nums[mid] > nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }

        return -1;
    }
};