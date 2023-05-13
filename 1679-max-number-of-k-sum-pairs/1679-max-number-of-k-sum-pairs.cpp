class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        int i = 0;
        int j = nums.size()-1;
        int counter = 0;
        while (i < j)
        {
            if (nums[i] + nums[j] > k)
            {
                j--;
            }
            else if (nums[i] + nums[j] < k)
            {
                i++;
            }
            else
            {
                i++;
                j--;
                counter++;
            }
        }
        return counter;
    }
};