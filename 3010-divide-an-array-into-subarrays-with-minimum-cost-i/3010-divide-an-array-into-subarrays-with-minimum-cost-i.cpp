class Solution {
public:
    int minimumCost(vector<int>& nums) {
        
        int first = nums[0];
        int lowestNum1 = 50;
        int lowestNum2 = 50;

        for (int i = 1; i < nums.size(); i++)
        {
            if (lowestNum1 > nums[i])
            {
                lowestNum2 = lowestNum1;
                lowestNum1 = nums[i];
            }
            else if (lowestNum1 == nums[i] || lowestNum2 > nums[i])
            {
                lowestNum2 = nums[i];
            }
        }

        return first + lowestNum1 + lowestNum2;
    }
};