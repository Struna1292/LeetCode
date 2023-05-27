class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        sort(begin(nums), end(nums));
        set<vector<int>> set;
        for (int i = 0; i < nums.size()-2; i++)
        {
            int j = i+1;
            int k = nums.size()-1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    set.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if (nums[i] + nums[j] + nums[k] > 0)
                {
                    k--;
                }
                else 
                {
                    j++;
                }
            }
        }

        for (auto it : set)
        {
            output.push_back(it);
        }
        
        return output;
    }
};