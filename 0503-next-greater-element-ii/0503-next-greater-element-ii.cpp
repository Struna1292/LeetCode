class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        vector<int> output(nums.size(), -1);

        for (int i = 0; i < output.size(); i++)
        {
            int counter = 0;

            int j = i+1;

            while (counter < nums.size()-1)
            {
                if (nums[j % nums.size()] > nums[i])
                {
                    output[i] = nums[j % nums.size()];
                    break;
                }
                j++;
                counter++;
            }
        }

        return output;
    }
};