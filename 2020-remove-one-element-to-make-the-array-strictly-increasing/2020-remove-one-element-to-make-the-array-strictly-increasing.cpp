class Solution {
public:
    bool isSorted(vector<int>& nums)
    {
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] <= nums[i-1])
            {
                return false;
            }
        }
        return true;
    }

    bool canBeIncreasing(vector<int>& nums) {
        
        for (int i = 1; i < nums.size(); i++)
        {   
            if (nums[i] <= nums[i-1])
            {
                vector<int> curr1 = nums;
                vector<int> curr2 = nums;

                curr1.erase(curr1.begin() + i-1);

                curr2.erase(curr2.begin() + i);

                if (isSorted(curr1) || isSorted(curr2))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }            
        }

        return true;
    }
};