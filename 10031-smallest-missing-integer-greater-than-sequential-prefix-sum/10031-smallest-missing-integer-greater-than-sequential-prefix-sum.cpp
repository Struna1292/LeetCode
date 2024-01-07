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

            if (nums[mid] > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        return false;
    }

    int missingInteger(vector<int>& nums) {
        
        int sum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i-1]+1 == nums[i])
            {
                sum += nums[i];
            }
            else
            {
                break;
            }
        }

        sort(begin(nums), end(nums));

        while (true)
        {
            if (binarySearch(nums, sum))
            {
                sum++;
            }
            else
            {
                break;
            }
        }

        return sum;
    }
};