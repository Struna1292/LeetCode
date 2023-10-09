class Solution {
public:
    int firstPosition(vector<int>& nums, int right, int target)
    {
        int left = 0;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid == 0 && nums[mid] == target)
            {
                return 0;
            }

            if (nums[mid] == target && nums[mid-1] < nums[mid])
            {
                return mid;
            }

            if (nums[mid] != target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }

    int lastPosition(vector<int>& nums, int left, int target)
    {
        int right = nums.size()-1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid == nums.size()-1 && nums[mid] == target)
            {
                return nums.size()-1;
            }

            if (nums[mid] == target && nums[mid] < nums[mid+1])
            {
                return mid;
            }

            if (nums[mid] != target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return -1;

        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> output(2, -1);

        int left = 0;
        int right = nums.size()-1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {   
                output[0] = mid;
                output[1] = mid;
                int firstPos = firstPosition(nums, mid-1, target);
                if (firstPos != -1)
                {
                    output[0] = firstPos;
                }

                int lastPos = lastPosition(nums, mid+1, target);
                if (lastPos != -1)
                {
                    output[1] = lastPos;
                }

                break;
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

        return output;
    }
};