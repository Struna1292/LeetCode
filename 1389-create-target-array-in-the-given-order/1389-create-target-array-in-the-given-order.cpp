class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> output(nums.size(), -1);

        for (int i = 0; i < index.size(); i++)
        {
            if (output[index[i]] == -1)
            {
                output[index[i]] = nums[i];
            }
            else
            {
                int j = index[i]+1;
                while (output[j] != -1)
                {
                    j++;
                }

                while (j > index[i])
                {
                    swap(output[j-1], output[j]);
                    j--;
                }

                output[index[i]] = nums[i];
            }
        }

        return output;
    }
};