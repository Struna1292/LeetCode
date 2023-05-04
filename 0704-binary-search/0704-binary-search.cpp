class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right)
        {
            int mid = (left+right)/2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else
            {
                if (nums[mid] > target)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return -1;
    }
};