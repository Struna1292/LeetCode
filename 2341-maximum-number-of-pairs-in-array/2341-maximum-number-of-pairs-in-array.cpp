class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        sort(begin(nums), end(nums));

        int pairs = 0;
        int i = 0;
        while (i < nums.size()-1)
        {
            if (nums[i] == nums[i+1])
            {
                pairs++;
                i += 2;
            }
            else
            {
                i++;
            }
        }

        vector<int> output;
        output.push_back(pairs);
        output.push_back(nums.size()-(pairs*2));

        return output;
    }
};