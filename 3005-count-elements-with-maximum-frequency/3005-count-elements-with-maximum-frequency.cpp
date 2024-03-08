class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        sort(begin(nums), end(nums));

        int biggest = 1;
        int currCounter = 1;
        int counter = 0;
        int prev = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {   
            if (nums[i] == prev)
            {
                currCounter++;
            }
            else
            {
                if (currCounter > biggest)
                {
                    biggest = currCounter;
                    counter = currCounter;
                }
                else if (currCounter == biggest)
                {
                    counter += currCounter;
                }
                currCounter = 1;
                prev = nums[i];
            }
        }

        if (currCounter > biggest)
        {
            counter = currCounter;
        }
        else if (currCounter == biggest)
        {
            counter += currCounter;
        }

        return counter;
    }
};