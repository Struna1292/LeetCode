class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        sort(begin(nums), end(nums));

        vector<int> output(2, 0);

        bool duplicateFound = false;
        bool missingFound = false;

        for (int i = 0; i < nums.size()-1; i++)
        {
            if (!missingFound)
            {
                if (!duplicateFound)
                {
                    if (nums[i] != i+1)
                    {
                        output[1] = i+1;
                        missingFound = true;
                    }
                }
                else
                {
                    if (nums[i+1] != i+1)
                    {
                        output[1] = i+1;
                        missingFound = true;
                    }
                }
            }

            if (nums[i] == nums[i+1])
            {
                output[0] = nums[i];
                duplicateFound = true;
            }
            
        }

        if (!missingFound)
        {
            output[1] = nums.size();
        }

        return output;
    }
};