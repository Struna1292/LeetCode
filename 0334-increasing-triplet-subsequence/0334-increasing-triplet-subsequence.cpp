class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        
        int i = 1;
        int j = nums.size()-2;

        int smallest = nums[0];
        int biggest = nums[nums.size()-1];

        vector<bool> hasBigger(nums.size(), false);
        vector<bool> hasSmaller(nums.size(), false);

        while (i < nums.size())
        {
            if (nums[i] > smallest)
            {
                hasSmaller[i] = true;
            }
            else
            {
                smallest = nums[i];
            }

            if (nums[j] < biggest)
            {
                hasBigger[j] = true;
            }
            else
            {
                biggest = nums[j];
            }

            i++;
            j--;
        }
        

        for (i = 1; i < nums.size()-1; i++)
        {
            if (hasBigger[i] && hasSmaller[i])
            {
                return true;
            }
        }


        return false;
    }
};