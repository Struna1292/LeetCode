class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target || nums[left] == target || nums[right] == target)
            {
                if (nums[mid] == target) return mid;
                else if (nums[left] == target) return left;
                else return right;
            }

            if ((target > nums[left] && target > nums[mid] && nums[left] > nums[mid]) || (target > nums[left] && target < nums[mid]) || (target < nums[left] && target < nums[mid]) && nums[left] > nums[mid])
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
};