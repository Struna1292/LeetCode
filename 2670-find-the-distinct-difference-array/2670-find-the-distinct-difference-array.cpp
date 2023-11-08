class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        
        vector<int> output(nums.size(), 0);


        for (int i = 0; i < nums.size(); i++)
        {

            set<int> prefix;
            set<int> suffix;

            for (int j = i; j >= 0; j--)
            {
                prefix.insert(nums[j]);
            }

            for (int j = i+1; j < nums.size(); j++)
            {
                suffix.insert(nums[j]);
            }

            output[i] = prefix.size() - suffix.size();
        }
        
        return output;
    }
};