class Solution {
public:

    vector<int> constructTransformedArray(vector<int>& nums) {
        
        vector<int> output = nums;

        for (int i = 0; i < nums.size(); i++)
        {
            int curr = nums[i];
            if (curr > 0)
            {
                curr %= nums.size();
            }
            else
            {
                curr *= -1;
                curr %= nums.size();

                curr = nums.size() - curr;
            }
            output[i] = nums[(i + curr) % nums.size()];
            
        }

        return output;
    }
};