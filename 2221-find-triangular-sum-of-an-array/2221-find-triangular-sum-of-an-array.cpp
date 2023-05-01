class Solution {
public:
    int triangularSum(vector<int>& nums) {

        int prev = nums[0];
        vector<int> curr;
        vector<int> empty;

        for (int i = 1; i < nums.size(); i++)
        {
            int num = (nums[i] + prev >= 10) ? (nums[i] + prev - 10) : (nums[i] + prev);

            curr.push_back(num);
            
            prev = nums[i];

            if (i+1 == nums.size())
            {
                nums = curr;
                curr = empty;
                i = 0;
                prev = nums[0];
            }

        }

        return nums[0];
    }
};