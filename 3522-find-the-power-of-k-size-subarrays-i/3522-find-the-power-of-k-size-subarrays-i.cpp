class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        if (k == 1)
        {
            return nums;
        }

        bool window = false;

        int currCounter = 1;

        vector<int> output;


        for (int i = 1; i < nums.size(); i++)
        {
            if (output.size() == nums.size()-k+1)
            {
                return output;
            }
            if (window)
            {
                if (nums[i] == nums[i-1]+1)
                {
                    output.push_back(nums[i]);
                }
                else
                {
                    window = false;
                    currCounter = 1;
                    for (int j = 0; j < k-1; j++)
                    {
                        output.push_back(-1);
                        if (output.size() == nums.size()-k+1)
                        {
                            return output;
                        }
                    }
                }
            }
            else
            {
                if (nums[i] == nums[i-1]+1)
                {
                    currCounter++;
                    if (currCounter == k)
                    {
                        window = true;
                        output.push_back(nums[i]);
                    }
                }
                else
                {
                    for (int j = 0; j < currCounter; j++)
                    {
                        output.push_back(-1);
                        if (output.size() == nums.size()-k+1)
                        {
                            return output;
                        }
                    }

                    currCounter = 1;
                }
            }
        }


        while (output.size() < nums.size()-k+1)
        {
            output.push_back(-1);
        }

        return output;
    }
};