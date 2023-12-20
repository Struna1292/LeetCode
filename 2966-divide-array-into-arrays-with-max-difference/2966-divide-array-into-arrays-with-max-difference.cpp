class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));

        vector<vector<int>> output;

        for (int i = 0; i < nums.size(); i+=3)
        {
            int j = i;
            int first = nums[j];
            vector<int> curr;

            for (int l = 0; l < 3; l++)
            {
                if ((first + k) < nums[j])
                {
                    return {};
                }
                curr.push_back(nums[j]);
                j++;
            }

            output.push_back(curr);
        }

        return output;
    }
};