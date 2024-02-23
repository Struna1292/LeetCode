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

    int minimumSum(int n, int k) {
        
        vector<int> currNums;

        int currSum = 0;

        int i = 1;

        while (currNums.size() != n)
        {
            if (!binarySearch(currNums, abs(i-k)) || i >= k)
            {
                currNums.push_back(i);
                sort(begin(currNums), end(currNums));
                currSum += i;
            }
            i++;
        }

        return currSum;
    }
};