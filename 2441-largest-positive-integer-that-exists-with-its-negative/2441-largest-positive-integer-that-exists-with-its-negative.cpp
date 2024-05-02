class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        sort(begin(nums), end(nums));

        int i = 0;
        int j = nums.size()-1;

        while (i < j)
        {
            int curr = nums[i] * -1;

            if (curr <= 0)
            {
                break;
            }
            else if (curr == nums[j])
            {
                return curr;
            }
            else if (curr > nums[j])
            {
                i++;
            }
            else
            {
                j--;
            }

        }


        return -1;
    }
};