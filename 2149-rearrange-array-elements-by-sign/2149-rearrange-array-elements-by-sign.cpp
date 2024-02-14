class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> negative;
        vector<int> positive;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                negative.push_back(nums[i]);
            }
            else
            {
                positive.push_back(nums[i]);
            }
        }

        vector<int> output;
        int counter1 = 0;
        int counter2 = 0;
        for (int i = 2; i < nums.size()+2; i++)
        {
            if (i % 2 == 0)
            {
                output.push_back(positive[counter1]);
                counter1++;
            }
            else
            {
                output.push_back(negative[counter2]);
                counter2++;
            }
        }
        return output;
    }
};