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

    int minOperations(vector<int>& nums, int k) {
        vector<int> collect;
        int output = 0;
        int j = nums.size()-1;

        while (collect.size() != k)
        {
            output++;
            if (nums[j] <= k)
            {
                if (!binarySearch(collect, nums[j]))
                {
                    collect.push_back(nums[j]);
                    sort(begin(collect), end(collect));
                }
            }
            j--;
        }

        return output;
    }
};