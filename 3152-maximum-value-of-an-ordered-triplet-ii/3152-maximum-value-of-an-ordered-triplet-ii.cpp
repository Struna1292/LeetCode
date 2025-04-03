class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
                vector<int> prevGreater(nums.size(), 0);
        vector<int> nextGreater(nums.size(), 0);

        int currBiggest = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            prevGreater[i] = currBiggest;

            if (currBiggest < nums[i])
            {
                currBiggest = nums[i];
            }
        }

        currBiggest = 0;

        for (int i = nums.size()-1; i >= 0; i--)
        {
            nextGreater[i] = currBiggest;

            if (currBiggest < nums[i])
            {
                currBiggest = nums[i];
            }
        }

        long long output = 0;
        for (int i = 1; i < nums.size()-1; i++)
        {
            if ((prevGreater[i] - nums[i]) * static_cast<long long>(nextGreater[i]) > output)
            {
                output = (prevGreater[i] - nums[i]) * static_cast<long long>(nextGreater[i]);
            }
        }

        return output;
    }
};