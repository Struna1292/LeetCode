class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(begin(nums),end(nums));

        int counter = 1;
        int temp = nums[0];
        
        int half;

        if (nums.size() % 2 == 0)
        {
            half = nums.size() / 2;
        }
        else
        {
            half = nums.size() / 2 + 1;
        }

        for (int i = 1; i < nums.size(); i++)
        {
            if (temp == nums[i])
            {
                counter++;
            }
            else
            {
                counter = 1;
                temp = nums[i];
            }
            if (counter >= half)
            {
                return nums[i];
            }
        }
        return temp;
    }
};