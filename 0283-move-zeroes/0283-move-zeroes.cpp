class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int> moved;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                moved.push_back(nums[i]);
            }
        }
        
        while (nums.size() != moved.size())
        {
            moved.push_back(0);
        }
        nums = moved;
    }
};