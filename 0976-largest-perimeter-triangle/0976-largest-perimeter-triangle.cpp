class Solution {
public:
    int largestPerimeter(vector<int>& nums) {

        sort(begin(nums), end(nums), greater<int>());

        for (int i = 0; i < nums.size()-2; i++)
        {   
            if (nums[i] < nums[i+1] + nums[i+2])
            {
                return nums[i] + nums[i+1] + nums[i+2];
            }
        }

        return 0;
    }
};