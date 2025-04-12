class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        
        if (nums.size() == 1)
        {
            return 0;
        }

        int output = 0;

        while (true)
        {
            
            int curr = nums[0] + nums[1];
            int index = 1;

            bool isSorted = true;
            for (int i = 1; i < nums.size(); i++)
            {
                if (nums[i-1] > nums[i])
                {
                    isSorted = false;
                }

                if (curr > nums[i] + nums[i-1])
                {
                    index = i;
                    curr = nums[i] + nums[i-1];
                }
            }

            if (isSorted)
            {
                break;
            }

            output++;

            nums[index-1] += nums[index];

            nums.erase(nums.begin()+index);
        }

        return output;
    }
};