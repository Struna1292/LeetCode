class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        if (nums.size() < 4)
        {
            return {};
        }
        
        sort(begin(nums), end(nums));

        set<vector<int>> currSet;

        for (int i = 0; i < nums.size()-3; i++)
        {
            for (int j = i+1; j < nums.size()-2; j++)
            {
                int k = j+1;
                int l = nums.size()-1;

                while (k < l)
                {
                    if (static_cast<long>(nums[i]) + static_cast<long>(nums[j]) + static_cast<long>(nums[k]) + static_cast<long>(nums[l]) == target)
                    {
                        currSet.insert({nums[i], nums[j], nums[k], nums[l]});

                        if (nums[k+1] == 0)
                        {
                            k++;
                        }
                        else
                        {
                            l--;
                        }
                    }
                    else if (static_cast<long>(nums[i]) + static_cast<long>(nums[j]) + static_cast<long>(nums[k]) + static_cast<long>(nums[l]) > target)
                    {
                        l--;
                    }
                    else
                    {
                        k++;
                    }
                }
            }
        }

        vector<vector<int>> output;

        for (auto itr = currSet.begin(); itr != currSet.end(); itr++)
        {   
            output.push_back(*itr);
        }

        return output;
    }
};