class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int counter = 1;
        int prev = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == prev)
            {
                counter++;
                if (counter == 3)
                {
                    nums.erase(nums.begin() + i);
                    i--;
                    counter--;
                }
            }
            else
            {
                counter = 1;
                prev = nums[i];
            }
        }

        return nums.size();
    }
};