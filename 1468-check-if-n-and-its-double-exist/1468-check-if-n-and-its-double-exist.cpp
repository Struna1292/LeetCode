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

    bool checkIfExist(vector<int>& arr) {
        
        sort(begin(arr), end(arr));

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] % 2 == 0)
            {
                int index = binarySearch(arr, (arr[i]/2));
                if (index != -1 && index != i)
                {
                    return true;
                }
            }
        }


        return false;
    }
};